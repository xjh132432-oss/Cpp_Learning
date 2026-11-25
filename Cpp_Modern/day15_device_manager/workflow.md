# Day15 Workflow — 综合项目实现与验收

## 已完成工作

- [x] 创建 Device 类，保存设备 ID、名称、温度和在线状态。
- [x] 实现 DeviceManager，管理设备的添加、删除、查找和遍历。
- [x] 使用 shared_ptr 管理设备对象。
- [x] 使用 weak_ptr 返回设备观察引用。
- [x] 实现温度筛选和在线设备统计。
- [x] 使用 ofstream 记录设备操作日志。
- [x] 创建 Task 类，保存任务名称、设备弱引用和回调函数。
- [x] 使用 std::function 统一任务回调接口。
- [x] 实现 Task::execute，处理设备已经销毁的情况。
- [x] 创建 TaskScheduler，保存和统一执行任务。
- [x] 使用 std::move 将 Task 移入任务容器。
- [x] 使用 Lambda 实现不同的设备操作。
- [x] 验证设备删除后 weak_ptr 失效。
- [x] 验证设备失效后任务安全跳过。
- [x] 验证多个任务连续修改同一设备的状态。
- [x] 验证 TaskScheduler::runAll 统一执行任务。
- [x] 完成综合项目运行测试。

## 收尾检查

- [x] 删除 main.cpp 中已经完成测试的旧注释代码。
- [x] 将 temperature 等变量和输出中的拼写统一。
- [x] 检查日志文件实际写入情况。
- [x] 检查 README、Workflow 和 Pitfalls。
- [x] 检查 Git 工作区并提交 Day15。

## 本日完成标准

Device、DeviceManager、Task 和 TaskScheduler 四个模块完成初步实现，综合运行输出符合预期。

后续不再扩展本项目功能，转入课程文档整理与 Git 收尾。
