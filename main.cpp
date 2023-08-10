/*
    文件等级：密一
    author:klug
    我从未许诺你玫瑰花园
    start:230710
    last:230810
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
    gpi.cosImg(2000,1000,50,1);
    cv::imwrite("/home/klug/img/pl.png",gpi.projectedImg);
    gpi.cosImg(2000,1000,50,0);
    cv::imwrite("/home/klug/img/pk.png",gpi.projectedImg);
    //zweiPhase::zweiPhaseCal pc;
#else
    phase::phaseConstruct pc;
#endif
    return -1;
}
