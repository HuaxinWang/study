#ifndef _LOGIN_H_
#define _LOGIN_H_


#define MAX_ID 20
#define MAX_NAME 20
#define MAX_PASSWD 20
#define MAX_MESSAGE 150

//教师信息结构体
struct teacher_info
{
    char id[MAX_ID];
    char name[MAX_NAME];
    char passwd[MAX_PASSWD];
    char major[20];
    int flag;
    char message[MAX_MESSAGE];

};

//教师信息链表
typedef struct teacher
{
    struct teacher_info tdata;
    struct teacher *next;
}tea;

//学生信息结构体
struct student_info
{
    int id;
    char name[MAX_NAME];
    char passwd[MAX_PASSWD];
    float chinese;
    float math;
    int flag;
    char message[MAX_MESSAGE];
};

//学生信息链表
typedef struct student
{
    struct student_info sdata;
    struct student *next;
}stu;

//管理员登录函数
void admin_login();

//生成随机验证码
int verify();

//管理员菜单
void admin_menu();

//读取教师文件信息
tea *readfile();

//将结构体链表写进教师文件
void writefile(tea *head);

//添加教师信息
void add_teacher();

//打印教师信息
void show_teacher();

//删除教师信息
void del_teacher();

//更新教师信息
void update_teacher();

//将结构体链表写进文件
void writefile(tea *head);



//教师菜单
void teacher_menu(char *id);

//教师登录函数
void teacher_login();

//读取学生文件信息
stu *readfile_stu();

//将结构体链表写进文件
void writefile_stu(stu *head);

//添加学生信息
void add_student();

//打印学生信息
void show_student();

//删除学生信息
void del_student();

//更新学生信息
void update_student();



//学生菜单
void student_menu(int id);

//学生登录函数
void student_login();

//更改学生密码
void change_stu_passwd(int id);

//更改教师密码
void change_tea_passwd(char *id);

//给老师留言
void leave_message();

//查看留言
void show_message();

//申请辞职
void resign();

#endif
