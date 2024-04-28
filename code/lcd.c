#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "lcd.h"

int fb = -1;
int* plcd = NULL;                       // 初始化指针
/*
    lcd_init ：屏幕初始化
    返回值 ：
        无返回值
*/
void lcd_init(void)
{
    //int fb;
    //打开设备
    fb = open("/dev/fb0",O_RDWR);       // 打开文件
    if(fb == -1)
    {
        perror("open /dev/fb0 error");  // 打印错误信息
        return ;
    }
/*
    int color = 0x66eeaa;               // 在开发板上显示颜色

    for(int i = 0;i < 480;i++)
    {
        for(int j = 0;j < 800;j++)
        {
            write(fb,&color,4);
        }
    }

    close(fb);
*/
    //(2)获取屏幕信息

    //（3）int* plcd = mmap
    plcd = mmap(NULL,
                    800*480*4,
                    PROT_WRITE | PROT_READ,
                    MAP_SHARED,
                    fb,
                    0);                 // 用来映射内核或文件中的一块内存或文件内容到应用空间
    if(plcd == MAP_FAILED)              // 映射失败
    {
        perror("map error");            // 打印错误信息
        return;
    }
}

/*
    lcd_dsrw_point : 显示一个像素点的颜色
    @x : 像素点横坐标
    @y : 像素点纵坐标
    @color ： 像素点颜色值
    返回值 ：
        无返回值
*/
void lcd_draw_point(int x,int y,int color)
{
    if(x>=0&&x<800&&y>=0&&y<480)        // 屏幕范围
    {
        *(plcd + 800*y + x) = color;    // 给像素点上色
    }
}


/*
    lcd_uinit ：解除映射和关闭文件
    返回值 ：
        无返回值
*/
//解除映射和关闭文件
void lcd_uinit()
{
    munmap(plcd,800*480*4);             // 解除映射
    close(fb);                          // 关闭文件
}

/*
    clear_lcd ：清屏
    @color : 清屏后的颜色值
    返回值 ：
        无返回值
*/
//清屏
void clear_lcd(int color)
{
    for(int i = 0;i < 480;i++)          // 横纵坐标范围
    {
        for(int j = 0;j < 800;j++)
        {
            lcd_draw_point(j,i,color);  // 上色
        }
    }
}


/*
    display_square : 在开发板上显示一个矩形
    @x0 : 矩形起始像素点的横坐标
    @y0 : 矩形起始像素点的纵坐标
    @w : 矩形的宽
    @h : 矩形的高
    @color : 矩形的颜色
    返回值 ： 
        无
*/
void display_square(int x0,int y0,int w,int h,int color)
{
    for(int y = 0;y < h;y++)            // 横纵坐标范围
    {
        for(int x = 0;x < w;x++)
        {
            lcd_draw_point(x + x0,y + y0,color);    // 上色
        }
    }
}

/*
    display_circle : 在开发板上显示圆
    @x0 : 圆心的横坐标
    @y0 : 圆心的纵坐标
    @r : 圆的半径
    @color : 矩形的颜色
    返回值 ： 
        无
*/
void display_circle(int x0,int y0,int r,int color)
{
    for(int y = 0;y < 480;y++)          // 横纵坐标范围
    {
        for(int x = 0;x < 800;x++)
        {
            if(((x-x0)*(x-x0)+(y-y0)*(y-y0))<r*r)   // 圆的范围
            {
                lcd_draw_point(x + x0,y + y0,color);    // 上色
            }
        }
    }
}

/*
    display_taiji : 在开发板上显示太极
    @x0 : 圆心的横坐标
    @y0 : 圆心的纵坐标
    @r : 圆的半径
    返回值 ： 
        无
*/
void display_taiji(int x0,int y0,int r)
{
    for(int y = 0;y < 480;y++)          // 横纵坐标范围
    {
        for(int x = 0;x < 800;x++)
        {
           if((x-x0)*(x-x0) + (y-y0)*(y-y0) <= r*r)     // 太极范围
            {
                if(x>x0)                                // 右边为白
                {
                    lcd_draw_point(x,y,0xFFFFFF);
                }
                if(x<x0)                                // 左边为黑
                {
                    lcd_draw_point(x,y,0x000000);
                }

                if((x-x0)*(x-x0)+(y-(y0-r/2))*(y-(y0-r/2))<=r/2*r/2)    
                {
                    lcd_draw_point(x,y,0x000000);

                    if((x-x0)*(x-x0)+(y-(y0-r/2))*(y-(y0-r/2))<=30*30) // 太极眼，白
                    {
                        lcd_draw_point(x,y,0xFFFFFF);
                    }
                }

                if((x-x0)*(x-x0)+(y-(y0+r/2))*(y-(y0+r/2))<=r/2*r/2)
                {
                    lcd_draw_point(x,y,0xFFFFFF);

                    if((x-x0)*(x-x0)+(y-(y0+r/2))*(y-(y0+r/2))<=30*30)  // 太极眼，黑
                    {
                        lcd_draw_point(x,y,0x000000);
                    }
                }
            }
        }
    }
}
