# Day13：关联式容器

## 学习目标

掌握 C++ STL 中四种常用关联式容器，理解它们的数据组织方式、基本操作和适用场景。

## 学习内容

### 1. std::map

- 存储 Key-Value 键值对。
- Key 唯一，按照 Key 自动排序。
- 常用接口：`insert()`、`find()`、`erase()`、`size()`、`operator[]`。
- `operator[]` 在 Key 不存在时会自动插入元素。

### 2. std::set

- 只存储 Key。
- 元素唯一，自动按照升序排列。
- 常用接口：`insert()`、`find()`、`erase()`、`size()`。

### 3. std::unordered_map

- 存储 Key-Value 键值对。
- 基于哈希表组织数据。
- 不保证遍历顺序。
- 查找平均时间复杂度为 O(1)，最坏为 O(n)。

### 4. std::unordered_set

- 只存储 Key。
- 基于哈希表组织数据。
- 元素唯一，不保证遍历顺序。
- 查找平均时间复杂度为 O(1)，最坏为 O(n)。

## 实验记录

### 01_map_student.cpp

使用 `std::map<int, std::string>` 实现学生学号与姓名的映射。

完成内容：
- 插入学生信息。
- 使用 Key 访问学生姓名。
- 删除指定学生。
- 遍历输出所有学生。

### 02_set_unique.cpp

使用 `std::set<int>` 实现整数去重与排序。

完成内容：
- 初始化包含重复元素的数据。
- 插入新元素。
- 验证重复插入。
- 查找并删除指定元素。
- 遍历输出集合。

### 03_unordered_map_frequency.cpp

使用 `std::unordered_map<std::string, int>` 统计单词频率。

完成内容：
- 遍历单词数组。
- 使用 `frequency[x]++` 统计出现次数。
- 查询指定单词的频率。
- 删除指定单词。
- 输出统计结果。

### 04_container_comparison.cpp

对比四种关联式容器。

完成内容：
- 分别创建四种容器。
- 插入相同类型的数据。
- 遍历并观察输出顺序。
- 验证有序容器与无序容器的区别。

## 核心知识总结

| 容器 | 存储形式 | 是否有序 | 元素是否唯一 |
|---|---|---|---|
| map | Key-Value | 是 | Key 唯一 |
| set | Key | 是 | 是 |
| unordered_map | Key-Value | 否 | Key 唯一 |
| unordered_set | Key | 否 | 是 |

### 复杂度

- `map`、`set`：查找 O(log n)。
- `unordered_map`、`unordered_set`：平均查找 O(1)，最坏 O(n)。

## 本日结论

完成四种关联式容器的基本使用和对比实验，掌握键值映射、集合、自动排序、去重、哈希查找等基本概念。

下一阶段：Day14——STL 综合实战。