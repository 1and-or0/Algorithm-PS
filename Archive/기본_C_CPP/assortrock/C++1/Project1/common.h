#pragma once

// 정적 변수 
static int g_iStatic = 0;

// 외부 변수
//extern int g_iExtern = 0;
//위처럼 선언하면 안됨!
// 올바른 외부 변수 사용 문법 - 참조될 파일에서는 정의 없이, 선언 없이 사용. 
// 그냥 common.h 를 참조한 모든 파일이 공동으로 사용 가능한 변수 g_iExtern이 있다고, 참조한 파일들에게 알려주는 것임
// .exe로 통합될 파일에서만 딱 한 번 정의해주면 되므로 어떤 파일에서 정의하든 상관은 없다
// 지금의 상황에서 common.h 를 func.cpp 와 main_12_31이 참조하므로
// common.h에서 정의하는 순간 통합과정에서 func.cpp와 main_12_31에서 중복정의를 한 셈이 됨
// 따라서 main_12_31 or func.cpp or 새로운 파일 중 한 곳에서만 정의하면 충분함!

extern int g_iExtern;

