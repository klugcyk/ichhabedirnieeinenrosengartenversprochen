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
    gpi.cosImg4PhaseShift(2000,1000,50,longitudinal,1);
    cv::imwrite("/home/klug/img/p1.png",gpi.projectedImg);
    gpi.cosImg4PhaseShift(2000,1000,50,transverse,2);
    cv::imwrite("/home/klug/img/p2.png",gpi.projectedImg);
    gpi.cosImg4PhaseShift(2000,1000,50,longitudinal,3);
    cv::imwrite("/home/klug/img/p3.png",gpi.projectedImg);
    gpi.cosImg4PhaseShift(2000,1000,50,transverse,4);
    cv::imwrite("/home/klug/img/p4.png",gpi.projectedImg);
    //zweiPhase::zweiPhaseCal pc;
#else
    phase::phaseConstruct pc;
#endif
    return -1;
}
