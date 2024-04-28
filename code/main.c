#include <stdio.h>
#include <unistd.h>
#include "lcd.h"
#include "bmp.h"
#include "touch.h"
#include "filelist.h"
#include "pthread.h"
#include <pthread.h>

int main()
{
    //1.屏幕初始化
    lcd_init();

    //2.操作屏幕
DESKTOP:                            
    display_bmp2(0,0,"desktop");        // 首页显示

    BiList* l = creat_list();           // 创建一个头结点
    BiNode* p = l->first;               // p指向
    // traverse_list(l);        // 遍历链表

    // int x,y;
    // get_user_touch(&x,&y);   // 求坐标
    // printf("(%d , %d)\n",x,y);

    get_button(l);          //  进入相册
    
    create_pth();           //  建立一个播放背景音乐的线程

    while(1)
    {
        display_bmp(0,0,"button2");     // 显示退出键
        int way = get_fingle_move();   // 获取手中划动方向
        // traverse_list(l,way); //遍历链表
        if(way == DOWN)         // 向下滑动进入上一张
        {
            p = p->prev;
            display_bmp2(0,0,p->data);
        }
        if(way == UP)           // 向上滑动进入上一张
        {
            p = p->next;
            display_bmp(0,0,p->data);
        }
        if(way == RIGHT)        // 向右滑动进入前一张
        {
            p = p->prev;
            display_bmp4(0,0,p->data);
        }
        if(way == LEFT)         // 向左滑动进入后一张
        {
            p = p->next;
            display_bmp3(0,0,p->data);
        }

        if(way == 0)
        {
            goto DESKTOP;   // 返回程序初始页面
        }
    }
    
    // char* bmp[] = {"./pic/pic1","./pic/pic2","./pic/pic3"};  // 数组实现图片自动播放
    // int i = 0;
    // while(1)
    // {
    //     display_bmp(0,0,bmp[i++]);
    //     sleep(3);
    //     if(i == 3)
    //     {
    //         i = 0;
    //     }
    // }
    // display_square(200,90,400,300,0xff0000); // 画方
    // display_circle(50,50,50,0xEE9A00);       // 画圆
    // display_taiji(400,240,160);

    //3.关闭映射和文件
    lcd_uinit();

    return 0;
}