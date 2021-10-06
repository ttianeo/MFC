# 助手破冰认人脸系统-详细版

## 任务核心逻辑

### 简单介绍

##### 		就是每次给出一堆名字，然后一张人脸图片（属于这些人的某个），通过 交互让用户选择某个名字，然后你返回结果

### 详细介绍

##### 		你需要利用某样东西存储若干学生信息，可以是数据库，也可以是文件。 某个学生信息包含：名字、学号、部门、人脸图片等。 你每次需要返回若干个学生名字（例如5），并展示其中一人的人脸图片。 让用户选择一个名字，交互方式任意，可以是网络请求，也可以是鼠标点 击，甚至是控制台输入数字。 你给出用户认人脸的结果，是否正确？更进一步，如果错误，告知用户该 人脸是哪位。 如果你不会图片操作，可以用字符串表示一张图片。也可以用 string 存 url，或 string 存图片相对路径。

### 改进记录

##### 2021.10.4

##### 1、随机生成题目（请确保Data.csv中的数据大于4条）
##### 2021.10.6
##### 1、增加后台数据增加接口



