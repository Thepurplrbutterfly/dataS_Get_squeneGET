typedef int data_t;
typedef struct sequenelist{
data_t * data;//利用指针创建容量可重构数组
int head;//头位置存储变量
int last;//尾位置存储变量
int maxlen;//数组容量
} sl;

sl * list_create(int);
int list_en(sl *);
void list_sequencing(sl *);
int list_sequencingGET(sl *, data_t);
