#include "Stage.h"


Stage::Stage(int min = MIN, int max = MAX, bool eval = false) : min(min), max(max), evaluation(eval){}

Stage::Stage(const Stage & s) : min(s.min), max(s.max), evaluation(s.evaluation){}
Stage::~Stage()
{
}
