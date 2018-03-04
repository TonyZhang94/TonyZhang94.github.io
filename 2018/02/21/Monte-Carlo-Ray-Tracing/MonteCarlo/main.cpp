#include <iostream>
using namespace std;

#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 200

// test();

int main(int argc, char *argv[]) {
	char sc;
	cout << "选择场景“1”或场景“2”：" << endl;
	cin >> sc;

	cout << "计算需要一些时间，请稍等 … " << endl;
	clock_t start = clock();

	World *wr = new World(new Model(sc), sc);
	Result *r = new Result(1, SIZE);
	
	wr->build(r->image, SIZE); // 构造场景
	wr->camera_ptr->render_scene(wr); // 渲染

	cout << "耗时：" << (double)(clock()-start)/CLOCKS_PER_SEC << endl;

	r->writeBMP(); // 将结果写入文件
	r->open_window(argc, argv); // OpenGL显示
}