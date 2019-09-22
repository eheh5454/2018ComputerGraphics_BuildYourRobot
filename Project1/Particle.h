#pragma once
#include "stdafx.h"
#define MAX_PARTICLE 300
class Particle {
	float f_x, f_y, f_z;
	float x[MAX_PARTICLE], y[MAX_PARTICLE], z[MAX_PARTICLE];
	float size;
	float m_x[MAX_PARTICLE], m_y[MAX_PARTICLE], m_z[MAX_PARTICLE];
	bool end_particle;

public:
	Particle(float x, float y, float z, float size);


	void DrawParticle();
	void Update();
	BOOL EndParticle();

};