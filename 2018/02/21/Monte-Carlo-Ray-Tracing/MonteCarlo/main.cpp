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
	cout << "ѡ�񳡾���1���򳡾���2����" << endl;
	cin >> sc;

	cout << "������ҪһЩʱ�䣬���Ե� �� " << endl;
	clock_t start = clock();

	World *wr = new World(new Model(sc), sc);
	Result *r = new Result(1, SIZE);
	
	wr->build(r->image, SIZE); // ���쳡��
	wr->camera_ptr->render_scene(wr); // ��Ⱦ

	cout << "��ʱ��" << (double)(clock()-start)/CLOCKS_PER_SEC << endl;

	r->writeBMP(); // �����д���ļ�
	r->open_window(argc, argv); // OpenGL��ʾ
}