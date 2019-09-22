#include "stdafx.h"
#include "Particle.h"
#include "Robot.h"

std::random_device rd3;
std::default_random_engine dre3{ rd3() };

std::uniform_real_distribution<float> particlepos{ 0.0,1.0 };
std::uniform_real_distribution<float> particlemove{ -3,3 };


Particle::Particle(float x, float y, float z, float size) :size(size / 2)
{
	end_particle = false;
	f_x = x, f_y = y, f_z = z;
	for (int i = 0; i < MAX_PARTICLE; ++i)
	{
		this->x[i] = x, this->y[i] = y, this->z[i] = z;
		m_x[i] = particlemove(dre3), m_y[i] = particlemove(dre3), m_z[i] = particlemove(dre3);
	}
	

}
BOOL Particle::EndParticle()
{
	return end_particle;
}
void Particle::Update()
{
	for (int i = 0; i < MAX_PARTICLE; ++i)
	{
		this->x[i] += m_x[i], this->y[i] += m_y[i], this->z[i] += m_z[i];
		if (std::fabs(x[i] - f_x) >= 100.f || std::fabs(z[i] - f_z) >= 100.f || std::fabs(y[i] - f_y) >= 100.f)
		{
			end_particle = true;
		}
	}
}

void Particle::DrawParticle()
{
	glPushMatrix();
	{
		for (int i = 0; i < MAX_PARTICLE; ++i)
		{
			glColor3f(1, 1,1);
			glTranslatef(x[i], y[i], z[i]);
			glutSolidCube(size);
		}
		
	}
	glPopMatrix();
}