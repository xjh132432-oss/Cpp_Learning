# Workflow — Day02

## 今日任务

学习并实践 C++ 智能指针 `std::unique_ptr`。

## 实际完成

- [x] 复习普通指针与堆对象的生命周期
- [x] 理解 `new` / `delete` 与内存泄漏
- [x] 初步理解 RAII
- [x] 引入 `<memory>` 并使用 `std::unique_ptr`
- [x] 使用 `std::make_unique<Student>()` 创建对象
- [x] 通过 `student->name` 等方式访问成员
- [x] 通过析构函数输出验证对象自动释放
- [x] 对比普通指针与智能指针的生命周期
- [x] 验证 `unique_ptr` 不支持复制
- [x] 使用 `std::move` 转移所有权
- [x] 观察移动后的指针状态及对象销毁时机


## 当前状态

Day02 的 `unique_ptr` 核心实践已完成，后续可以继续巩固 RAII、对象生命周期和所有权管理。

## Git 提交

建议提交信息：

```text
feat(day02): learn unique_ptr and RAII
```
