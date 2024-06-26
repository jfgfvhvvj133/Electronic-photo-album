#ifndef __BMP_H__
#define __BMP_H__

/*
    display_bmp :从下往上显示bmp图片
    @x0 : 图片的初始横坐标
    @y0 : 图片的初始纵坐标
    @bmpfile : 要显示哪个图片
    返回值 :
        返回 -1 文件打开失败
        返回 -2 不是BMP文件
        返回 -3 无色深
*/
int display_bmp(int x0,int y0,char* bmpfile);

/*
    display_bmp2 :从上往下显示bmp图片
    @x0 : 图片的初始横坐标
    @y0 : 图片的初始纵坐标
    @bmpfile : 要显示哪个图片
    返回值 :
        返回 -1 文件打开失败
        返回 -2 不是BMP文件
        返回 -3 无色深
*/
int display_bmp2(int x0,int y0,char* bmpfile);

/*
    display_bmp3 :从右向左显示bmp图片
    @x0 : 图片的初始横坐标
    @y0 : 图片的初始纵坐标
    @bmpfile : 要显示哪个图片
    返回值 :
        返回 -1 文件打开失败
        返回 -2 不是BMP文件
        返回 -3 无色深
*/
int display_bmp3(int x0,int y0,char* bmpfile);

/*
    display_bmp4 : 从左向右显示bmp图片
    @x0 : 图片的初始横坐标
    @y0 : 图片的初始纵坐标
    @bmpfile : 要显示哪个图片
    返回值 :
        返回 -1 文件打开失败
        返回 -2 不是BMP文件
        返回 -3 无色深
*/
int display_bmp4(int x0,int y0,char* bmpfile);

#endif