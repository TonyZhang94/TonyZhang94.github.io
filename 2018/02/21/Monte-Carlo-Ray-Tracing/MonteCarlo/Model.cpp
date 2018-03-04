#include "Model.h"

Model::Model(char sc) {
	string path = string("scene0") + sc + string(".obj");
	string mtlpath = string("scene0") + sc + string(".mtl");

	//cout << path << endl;
	//cout << mtlpath << endl;
	ifstream rfile(path);
	ifstream mtlfile(mtlpath);

	if (!rfile) {
		cout << "read obj file error" << endl;
	}

	if (!mtlfile) {
		cout << "read mtl file error" << endl;
	}

	string s;
	string curMaterial;
	stringstream ss;

	int i = 0;
	while (getline(rfile, s)) {
		if (s.length() < 1)
			continue;

		if (s[0] == 'v' && s[1]==' ') {
			s = s.substr(2);
			ss << s;
			Vertex tmp;
			ss >> tmp.x >> tmp.y >> tmp.z;
			vertexList.push_back(tmp);
			ss.clear();
		}
		else if (s[0] == 'v' && s[1] == 't') {
			s = s.substr(3);
			ss << s;
			Texture tmp;
			ss >> tmp.x >> tmp.y;
			texList.push_back(tmp);
			ss.clear();
		}
		else if (s[0] == 'v' && s[1] == 'n') {
			s = s.substr(3);
			ss << s;
			Norm tmp;
			ss >> tmp.x >> tmp.y>>tmp.z;
			normList.push_back(tmp);
			ss.clear();
		}
		else if (s[0] == 'f') {
			Face tmp;
			s = s.substr(2);
			int num=sscanf_s(s.c_str(), "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &tmp.v1, &tmp.t1, &tmp.n1, &tmp.v2, &tmp.t2, &tmp.n2, &tmp.v3, &tmp.t3, &tmp.n3, &tmp.v4, &tmp.t4, &tmp.n4);
			if (num == 9) {
				tmp.v4 = -1;
				tmp.n4 = -1;
				tmp.t4 = -1;
			}
			tmp.material = curMaterial;

			faceList.push_back(tmp);
			ss.clear();
		}
		else if (s[0] == 'u') {
			s = s.substr(7);
			curMaterial = s;

		}
	}

	while (getline(mtlfile, s)) {
		if (s[0] == 'n' && s[1] == 'e') {
			s = s.substr(7);
			curMaterial = s;
		}
		else if (s[0] == 'K' && s[1] == 'd') {
			s = s.substr(3);
			ss << s;
			ss >> mtlMap[curMaterial].kd[0] >> mtlMap[curMaterial].kd[1] >> mtlMap[curMaterial].kd[2];
			ss.clear();
		}
		else if (s[0] == 'K' && s[1] == 'a') {
			s = s.substr(3);
			ss << s;
			ss >> mtlMap[curMaterial].ka[0] >> mtlMap[curMaterial].ka[1] >> mtlMap[curMaterial].ka[2];
			ss.clear();
		}
		else if (s[0] == 'T' && s[1] == 'f') {
			s = s.substr(3);
			ss << s;
			ss >> mtlMap[curMaterial].tf[0] >> mtlMap[curMaterial].tf[1] >> mtlMap[curMaterial].tf[2];
			ss.clear();
		}
		else if (s[0] == 'K' && s[1] == 's') {
			s = s.substr(3);
			ss << s;
			ss >> mtlMap[curMaterial].ks[0] >> mtlMap[curMaterial].ks[1] >> mtlMap[curMaterial].ks[2];
			ss.clear();
		}
		else if (s[0] == 'N' && s[1] == 'i') {
			s = s.substr(3);
			ss << s;
			ss >> mtlMap[curMaterial].ni;
			ss.clear();
		}
	}

	rfile.close();
	mtlfile.close();
}

void
	Model::print(void) const {
		for (vector<Face>::const_iterator  it = faceList.begin(); it != faceList.end(); it++) {
			cout << (*it).material << endl;
			printf("%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n", (*it).v1, (*it).t1, (*it).n1, (*it).v2, (*it).t3, (*it).n3, (*it).v3, (*it).t3, (*it).n3, (*it).v4, (*it).t4, (*it).n4);

		}
}