/*
    文件等级：密一
    author:klug
    我从未许诺你玫瑰花园
    start:230710
    last:230811
*/

#include <iostream>
#include "source.hpp"
#include "PhaseRefactoring/phase_construct.hpp"
#include "zweiPhaseRefactoring/zwei_phase_cal.hpp"
#include <opencv2/opencv.hpp>
#include "projectedImg/projected_img.hpp"

#define zweiChoose

int main(/*int argc, char *argv[]*/)
{
#ifdef zweiChoose
    projectImg::geneProjectImg gpi;

    //gpi.lissajousImgRGB(1000,1000/*,20,5,3,4,Pi/6*/);
    gpi.lineImg(1000,1000,255,50,longitudinal);
    cv::imwrite("/home/klug/img/lsr.png",gpi.projectedImg);
    //zweiPhase::zweiPhaseCal pc;
#else
    phase::phaseConstruct pc;
#endif
    return -1;
}
