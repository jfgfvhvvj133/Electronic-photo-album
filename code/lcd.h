#ifndef __LCD_H__
#define __LCD_H__

/*
    lcd_init ：屏幕初始化
    返回值 ：
        无返回值
*/
void lcd_init(void);

/*
    lcd_dsrw_point : 显示一个像素点的颜色
    @x : 像素点横坐标
    @y : 像素点纵坐标
    @color ： 像素点颜色值
    返回值 ：
        无返回值
*/
void lcd_draw_point(int x,int y,int color);

/*
    lcd_uinit ：解除映射和关闭文件
    返回值 ：
        无返回值
*/
void lcd_uinit();

/*
    clear_lcd ：清屏
    @color : 清屏后的颜色值
    返回值 ：
        无返回值
*/
void clear_lcd(int color);

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
void display_square(int x0,int y0,int w,int h,int color);

/*
    display_circle : 在开发板上显示圆
    @x0 : 圆心的横坐标
    @y0 : 圆心的纵坐标
    @r : 圆的半径
    @color : 矩形的颜色
    返回值 ： 
        无
*/
void display_circle(int x0,int yo,int r,int color);

/*
    display_taiji : 在开发板上显示太极
    @x0 : 圆心的横坐标
    @y0 : 圆心的纵坐标
    @r : 圆的半径
    返回值 ： 
        无
*/
void display_taiji(int x0,int y0,int r);

#endif