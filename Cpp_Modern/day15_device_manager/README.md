# Day15 — Modern C++ 综合项目：Device Manager & Task Scheduler

## 1. 项目目标

通过一个设备管理与任务调度项目，综合运用 Modern C++ 的核心语言特性和工程实践。

项目模拟设备管理系统：

- 管理多个设备及其状态。
- 支持设备添加、删除、查找和筛选。
- 使用智能指针管理设备生命周期。
- 使用任务对象保存设备引用和回调函数。
- 通过任务调度器统一执行任务。
- 当设备销毁后，安全跳过绑定该设备的任务。

## 2. 项目结构

    day15_device_manager/
    ├── CMakeLists.txt
    ├── README.md
    ├── include/
    │   ├── Device.h
    │   ├── DeviceManager.h
    │   ├── Task.h
    │   └── TaskScheduler.h
    ├── src/
    │   ├── Device.cpp
    │   ├── DeviceManager.cpp
    │   ├── Task.cpp
    │   ├── TaskScheduler.cpp
    │   └── main.cpp
    └── logs/

## 3. 模块设计

### Device

设备实体类，保存设备基本信息：

- id：设备编号。
- name：设备名称。
- temperature：设备温度。
- online：设备在线状态。

提供属性读取和状态修改接口。

### DeviceManager

设备管理类，负责设备集合的管理。

主要功能：

- addDevice：添加设备，避免重复 ID。
- removeDevice：删除设备。
- findDevice：根据 ID 查找设备。
- printAll：打印全部设备。
- filterByTemperature：筛选温度超过阈值的设备。
- countOnline：统计在线设备数量。

使用 `std::vector<std::shared_ptr<Device>>` 管理设备对象，并使用 `std::ofstream` 记录操作日志。

### Task

任务类，保存：

- 任务名称。
- 指向设备的 `std::weak_ptr<Device>`。
- `std::function<void(Device&)>` 回调函数。

执行任务时，通过 `weak_ptr::lock()` 尝试获取设备的临时所有权。

如果设备已经销毁，则跳过回调，避免访问无效对象。

### TaskScheduler

任务调度器，使用 `std::vector<Task>` 保存任务。

主要功能：

- addTask：添加任务，使用移动语义将任务放入容器。
- runAll：遍历并执行所有任务。

## 4. 核心设计

### 设备所有权

DeviceManager 使用 `shared_ptr` 持有设备对象。

Task 使用 `weak_ptr` 观察设备，不参与设备所有权管理。

当 DeviceManager 删除设备，并且没有其他 `shared_ptr` 持有该对象时，设备被销毁，相关 `weak_ptr` 自动失效。

### 安全执行任务

Task 执行时调用 `weak_ptr::lock()`：

- 获取成功：通过临时 `shared_ptr` 保证设备在回调期间存活。
- 获取失败：说明设备已不存在，跳过任务。

### 回调机制

使用 `std::function<void(Device&)>` 统一回调接口。

Lambda 可以封装不同的设备操作，使任务调度器不必关心具体任务内容。

### 移动语义

TaskScheduler 添加任务时使用 `std::move`，避免不必要的任务对象拷贝。

## 5. 综合测试

### 测试一：设备任务执行

创建设备 1，绑定回调，将温度设置为 50。

实际输出：

    tempteature:50

### 测试二：设备销毁与 weak_ptr 失效

删除设备 1，检查弱引用状态，并再次执行绑定该设备的任务。

实际输出：

    not exists
    This Device Does Not Exists

### 测试三：多任务连续执行

设备 2 初始温度为 35.2。

- Task2：当前温度增加 5。
- Task3：当前温度增加 10。

最终温度：

    50.2

### 测试四：统一任务调度

将三个任务移动到 TaskScheduler，调用 `runAll()`。

实际输出：

    -----------run all tasks-----------
    This Device Does Not Exists
    temperature: 50.2

验证了调度器能够统一执行任务，并在设备已经销毁时安全跳过对应任务。

## 6. 涉及的 Modern C++ 知识

| 知识点 | 项目应用 |
|---|---|
| RAII | ofstream 自动释放文件资源 |
| unique_ptr | 前期资源管理练习 |
| shared_ptr | DeviceManager 持有设备 |
| weak_ptr | Task 弱引用设备 |
| std::move | Task 移动到调度器 |
| Lambda | 设备操作回调 |
| std::function | 统一任务回调接口 |
| STL 算法 | 查找、筛选和统计设备 |
| const 成员函数 | 只读查询与任务执行接口 |
| CMake | 多文件工程构建 |

## 7. 项目总结

Day15 将前面学习的现代 C++ 特性整合到一个完整的小型工程中。

重点不在于增加新的 STL 容器知识，而在于理解：

1. 对象所有权应该由谁管理。
2. 如何避免悬空引用和无效对象访问。
3. 如何使用移动语义减少不必要的拷贝。
4. 如何使用 Lambda 和 std::function 实现可扩展的任务回调。
5. 如何将多个类组织成职责清晰的模块。

至此，Cpp_Modern 的综合实践项目完成。