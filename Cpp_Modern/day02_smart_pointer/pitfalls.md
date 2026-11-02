## 遇到的问题与解决

### 问题一：找不到 `std::unique_ptr`

原因：缺少 `<memory>` 头文件。

解决：添加 `#include <memory>`。

### 问题二：`make_unique` 无法匹配 Student 构造函数

原因：`Student` 没有接受三个参数的构造函数。

解决：先使用默认构造，再给 `name`、`age` 和 `score` 赋值。

### 问题三：复制 unique_ptr 失败

原因：`unique_ptr` 禁止复制，以保证独占所有权。

解决：使用 `std::move` 转移所有权。
