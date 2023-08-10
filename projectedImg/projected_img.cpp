/*
    文件等级：密一
    author:klug
    献给我的心上人等待天使的妹妹
    start:230810
    last:230810
*/

#include "projectedImg/projected_img.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace projectImg
{

geneProjectImg::geneProjectImg()
{

}

geneProjectImg::~geneProjectImg()
{

}

/*
    cos条纹生成
    @row:生成投影图像的行数
    @col:生成投影图像的列数
    @wavelength:生成投影图像的波长
    @type:生成条纹方向，0：横向，1：纵向
*/
void geneProjectImg::cosImg(int row,int col,int waveLength,bool type)
{
    cv::Mat resImg(row,col,CV_8UC1);

    int wave=0;
    if(type==1)
    {
        for(size_t col_=0;col_<col;col_++)
        {
            //计算条纹数值
            int value=0;
            //
            for(size_t row_=0;row_<row;row_++)
            {

                resImg.at<uchar>(row_,col_)=value;
                wave++;
            }

            if(wave>=waveLength)
            {
                wave=0;
            }
        }
    }
    else
    {
        for(size_t row_=0;row_<row;row_++)
        {
            //计算条纹数值
            int value=0;

            for(size_t col_=0;col_<col;col_++)
            {

                resImg.at<uchar>(row_,col_)=value;
                wave++;
            }

            if(wave>=waveLength)
            {
                wave=0;
            }
        }
    }

    projectedImg=resImg;
}

/*
    sin条纹生成
    @row:生成投影图像的行数
    @col:生成投影图像的列数
    @wavelength:生成投影图像的波长
    @type:生成条纹方向，0：横向，1：纵向
*/
void geneProjectImg::sinImg(int row,int col,int waveLength,bool type)
{

}

};
