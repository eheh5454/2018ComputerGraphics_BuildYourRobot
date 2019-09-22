#pragma once
#include "stdafx.h"

struct LightRGBA {
	GLfloat r, g, b, a;
};


class LightObject {
	float size;
	GLenum gl_light_num;

	bool light_1;
	bool light_2;
	float c_r, c_g, c_b, c_a;

	GLfloat Pos1[4];
	GLfloat Pos2[4];
	GLfloat AmbientLight1[4]; //주변 조명
	GLfloat DiffuseLight1[4]; // 산란반사 조명
	GLfloat SpecularLight1[4]; // 거울반사 조명

	GLfloat AmbientLight2[4]; //주변 조명
	GLfloat DiffuseLight2[4]; // 산란반사 조명
	GLfloat SpecularLight2[4]; // 거울반사 조명
public:
	LightObject(GLfloat board_size);
	~LightObject();

	void SetAmbientLightRGBA(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat a1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat a2);
	void SetDiffuseLightRGBA(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat a1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat a2);
	void SetSpecularLightRGBA(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat a1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat a2);

	void ChangeAmbientLightRGBA(bool);
	void ChangeDiffuseLightRGBA(bool);
	void ChangeSpecularLightRGBA(bool);

	void OnOffLight1();
	void OnOffLight2();


	void DrawLightObject();

};