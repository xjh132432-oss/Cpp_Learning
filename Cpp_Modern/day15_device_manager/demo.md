# **Cpp_Modern · Day15：综合实践项目**

今天不再学习新的 STL 容器，也不继续堆砌语法。我们把前面学过的现代 C++ 特性组合起来，完成一个具备实际工程结构的小项目。

**项目：智能设备管理与任务调度系统**

综合实践

[SensorAlerts.io — Real-Time Building Intelligence](https://images.openai.com/static-rsc-4/zblqdQtb55zpQOpv77LE_8rZcKWA7ABLAq5TFhL0-uxT_iWTYRcgTZdrkAGpitbXUDz_HiaLsqFIpjBVrw23qxcsuRFoK-b8S6_hqUxFzsxqz95EmUdAs4GNvxSETWl16PCiWPQTebW3ybcG2Y4ZwipQDYr0QBM19m_4dVOL6BU?purpose=inline)

[sensoralerts.io](https://sensoralerts.io/?utm_source=chatgpt.com)

**模拟场景**

管理多个设备，记录设备状态和温度；根据条件筛选设备；向设备派发任务；设备销毁后，任务系统能够识别失效对象。

**技术要求**

C++17 · RAII · 智能指针 · 移动语义 · Lambda · STL 算法 · CMake

## **一、为什么做这个项目？**

你之前学到的知识都是独立的：

- `unique_ptr`：独占资源。
- `shared_ptr`：共享资源。
- `weak_ptr`：观察资源。
- 移动语义：转移资源所有权。
- Lambda：将行为作为参数传递。
- RAII：让资源生命周期与对象生命周期绑定。

但实际工程中，它们不会单独出现。

例如，一个设备管理系统需要解决：

1. 谁负责设备的生命周期？
2. 任务系统如何访问设备？
3. 设备被删除后，任务如何避免访问失效对象？
4. 如何通过 Lambda 定义不同任务？
5. 如何根据设备状态筛选、排序？
6. 如何管理日志文件的打开和关闭？

这就是本项目要解决的问题。

## **二、项目结构**

项目名称：`day15_device_manager`

```
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
```

采用头文件与源文件分离，不把所有逻辑堆在 `main.cpp` 中。

## **三、系统架构**

**main.cpp**

程序入口：创建管理器、注册设备、提交任务

**DeviceManager**

设备管理

- 注册设备
- 删除设备
- 查找设备
- 筛选设备

**TaskScheduler**

任务调度

- 创建任务
- 保存任务
- 执行任务
- 处理失效引用

**Device**

设备实体：ID、名称、温度、在线状态

各模块职责：

| 模块            | 负责什么          |
| ------------- | ------------- |
| Device        | 描述设备自身的数据和行为  |
| DeviceManager | 管理设备集合与设备生命周期 |
| Task          | 描述一个具体任务      |
| TaskScheduler | 保存、调度和执行任务    |
| main          | 组织整个程序运行      |

## **四、技术取舍与要求**

这里先明确每种技术为什么用，而不是为了展示知识点强行使用。

| 技术              | 项目中的用途             | 设计选择                    |
| --------------- | ------------------ | ----------------------- |
| `shared_ptr`    | DeviceManager 管理设备 | 管理器持有设备所有权              |
| `weak_ptr`      | Task 观察设备          | 不延长设备生命周期               |
| `std::function` | 保存任务回调             | 统一不同 Lambda 的调用形式       |
| Lambda          | 任务执行、条件筛选          | 将行为传递给调度器               |
| `std::move`     | 转移任务对象             | 避免不必要的复制                |
| RAII            | 管理日志文件             | 使用 `std::ofstream` 自动关闭 |
| Rule of Zero    | Device 等普通数据类      | 尽量不手写特殊成员函数             |

注意：这里选择 `shared_ptr` 并不是因为它永远比 `unique_ptr` 好，而是因为任务需要持有 `weak_ptr` 观察设备。

管理器是设备的强所有权持有者，任务只观察设备，不拥有设备。

## **五、功能需求**

这是完整的项目验收要求。先看完全部要求，再开始实现。

### **模块一：设备类 Device**

定义设备实体，至少包含：

- `id`：设备编号。
- `name`：设备名称。
- `temperature`：当前温度。
- `online`：是否在线。

要求：

1. 实现构造函数。
2. 提供获取设备信息的方法。
3. 提供修改温度的方法。
4. 提供修改在线状态的方法。
5. 优先使用 Rule of Zero，不要无意义地手写五大特殊成员函数。

### **模块二：设备管理器 DeviceManager**

使用 `std::vector<std::shared_ptr<Device>>` 管理设备。

要求：

1. `addDevice()`：添加设备。
2. `removeDevice()`：根据 ID 删除设备。
3. `findDevice()`：根据 ID 查找设备，返回 `weak_ptr`。
4. `printAll()`：输出全部设备。
5. `filterByTemperature()`：使用 Lambda 筛选高温设备。
6. `countOnline()`：使用 Lambda 统计在线设备数量。
7. 设备管理器维护一个日志文件，记录设备添加和删除事件。

特别要求：删除设备时，不能让任务系统继续使用已经销毁的设备。

### **模块三：任务类 Task**

每个任务包含：

- 任务名称。
- 目标设备的 `weak_ptr`。
- 任务执行回调 `std::function<void()>`。

要求：

1. 能够保存任务名称。
2. 能够关联目标设备。
3. 能够保存 Lambda 回调。
4. 能够执行任务。
5. 执行前检查设备是否仍然有效。
6. 如果设备已经销毁，输出任务失效信息，而不是访问无效对象。

### **模块四：任务调度器 TaskScheduler**

要求：

1. 保存多个任务。
2. 提供 `addTask()` 添加任务。
3. 提供 `runAll()` 执行所有任务。
4. 通过移动语义将任务加入内部任务集合。
5. 任务执行时正确处理 `weak_ptr::lock()` 失败的情况。

### **模块五：主程序**

至少完成以下流程：

1. 创建 DeviceManager。
2. 添加三个设备。
3. 输出所有设备。
4. 筛选温度超过 80 的设备。
5. 统计在线设备。
6. 创建任务调度器。
7. 为设备创建不同任务。
8. 执行全部任务。
9. 删除其中一个设备。
10. 再次执行任务，验证失效设备的处理。
11. 程序退出，观察资源自动释放。

## **六、关键接口设计**

下面是建议的接口，不是完整答案。你需要自行实现函数内部逻辑。

`Device.h`

```
class Device {
public:
    Device(int id, std::string name, double temperature);

    int getId() const;
    const std::string& getName() const;
    double getTemperature() const;
    bool isOnline() const;

    void setTemperature(double temperature);
    void setOnline(bool online);

private:
    int id;
    std::string name;
    double temperature;
    bool online = true;
};
```

`DeviceManager.h`

```
class DeviceManager {
public:
    std::weak_ptr<Device> addDevice(
        int id,
        const std::string& name,
        double temperature
    );

    bool removeDevice(int id);

    std::weak_ptr<Device> findDevice(int id) const;

    void printAll() const;

    void filterByTemperature(double threshold) const;

    std::size_t countOnline() const;

private:
    std::vector<std::shared_ptr<Device>> devices;
    std::ofstream logFile;
};
```

`Task.h`

```
class Task {
public:
    Task(
        std::string name,
        std::weak_ptr<Device> device,
        std::function<void(Device&)> callback
    );

    void execute() const;

private:
    std::string name;
    std::weak_ptr<Device> device;
    std::function<void(Device&)> callback;
};
```

`TaskScheduler.h`

```
class TaskScheduler {
public:
    void addTask(Task task);

    void runAll() const;

private:
    std::vector<Task> tasks;
};
```

这里的 `std::function<void(Device&)>` 表示：任务回调接收一个设备引用，不返回结果。

这样 Task 负责检查设备是否有效，回调只负责具体操作。

## **七、验收标准**

最终验收

| 验收项    | 通过条件                 |
| ------ | -------------------- |
| 生命周期   | 删除设备后，对应 weak_ptr 失效 |
| 智能指针   | 没有不必要的裸 `new/delete` |
| Lambda | 筛选、统计、任务回调均使用 Lambda |
| 移动语义   | 任务添加过程使用移动语义         |
| RAII   | 日志文件自动关闭             |
| 模块化    | 头文件和源文件分离            |
| CMake  | 可以正常构建运行             |
| 运行结果   | 删除设备后，任务不会访问失效对象     |

## **八、今天的实施顺序**

不把项目拆成十几个零碎练习，按照实际工程依赖关系完成：

1. **第一阶段：搭建工程**

   创建目录结构、CMakeLists.txt，完成 Device 类。
2. **第二阶段：设备管理**

   完成 DeviceManager，理解 shared_ptr 和 weak_ptr 的所有权关系。
3. **第三阶段：任务系统**

   完成 Task 和 TaskScheduler，组合 Lambda、std::function 和移动语义。
4. **第四阶段：集成测试**

   完成 main.cpp，验证设备删除后的任务失效处理。
5. **第五阶段：工程收尾**

   编译、运行、排错，整理 README、workflow、pitfalls 和 Git 提交。

## **九、现在开始：第一阶段**

先创建项目目录和空文件，不要一次性把所有代码写完。

建议在 `Cpp_Modern` 仓库中创建：

```
day15_device_manager/
```

第一阶段你需要完成：

- 创建上述项目目录结构。
- 编写 `CMakeLists.txt`，要求 C++17。
- 编写 `Device.h` 和 `Device.cpp`。
- 编写一个简单的 `main.cpp`，创建两个 Device 并输出信息。
- 使用 CMake 成功构建运行。

**第一阶段验收：** 能创建两个设备对象，输出 ID、名称、温度和在线状态。

先完成这一阶段，把你的目录结构、CMakeLists.txt、Device.h、Device.cpp 和运行结果发给我。我会按工程代码审查的方式检查，而不是直接替你写完整项目。