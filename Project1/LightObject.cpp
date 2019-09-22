#include "stdafx.h"
#include "LightObject.h"

LightObject::LightObject(GLfloat board_size) : size{ board_size / 50 }
{
	Pos1[0] = board_size;
	Pos1[1] = size;
	Pos1[2] = 0;
	Pos1[3] = 1;

	Pos2[0] = -board_size;
	Pos2[1] = size;
	Pos2[2] = 0;
	Pos2[3] = 1;

	c_r = 0.1, c_g = 0.1, c_b = 0.1, c_a = 0.1;

	light_1 = true;
	light_2 = true;
}
LightObject::~LightObject()
{

}


void LightObject::SetAmbientLightRGBA(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat a1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat a2)
{
	AmbientLight1[0] = r1;
	AmbientLight1[1] = g1;
	AmbientLight1[2] = b1;
	AmbientLight1[3] = a1;

	AmbientLight2[0] = r2;
	AmbientLight2[1] = g2;
	AmbientLight2[2] = b2;
	AmbientLight2[3] = a2;
}

void LightObject::SetDiffuseLightRGBA(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat a1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat a2)
{
	DiffuseLight1[0] = r1;
	DiffuseLight1[1] = g1;
	DiffuseLight1[2] = b1;
	DiffuseLight1[3] = a1;

	DiffuseLight2[0] = r2;
	DiffuseLight2[1] = g2;
	DiffuseLight2[2] = b2;
	DiffuseLight2[3] = a2;
}

void LightObject::SetSpecularLightRGBA(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat a1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat a2)
{
	SpecularLight1[0] = r1;
	SpecularLight1[1] = g1;
	SpecularLight1[2] = b1;
	SpecularLight1[3] = a1;

	SpecularLight2[0] = r2;
	SpecularLight2[1] = g2;
	SpecularLight2[2] = b2;
	SpecularLight2[3] = a2;
}

void LightObject::DrawLightObject()
{
	glEnable(GL_LIGHTING);
	//glRotatef(90, 0, 0, 1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight1);
	glLightfv(GL_LIGHT1, GL_POSITION, Pos1);

	if (light_1)
		glEnable(GL_LIGHT1);
	else if (!light_1)
		glDisable(GL_LIGHT1);


	//glRotatef(-90, 0, 1, 0);
	glLightfv(GL_LIGHT2, GL_AMBIENT, AmbientLight2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, DiffuseLight2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, SpecularLight2);
	glLightfv(GL_LIGHT2, GL_POSITION, Pos2);
	if (light_2)
		glEnable(GL_LIGHT2);
	else if (!light_2)
		glDisable(GL_LIGHT2);


}

void LightObject::ChangeAmbientLightRGBA(bool updown) //up  = true, down = false
{
	switch (updown)
	{
	case true:
		for (int i = 0; i < 3; ++i)
		{
			if (AmbientLight1[i] < 1 && AmbientLight2[i] < 1)
			{
				this->AmbientLight1[0] += c_r;
				this->AmbientLight1[1] += c_g;
				this->AmbientLight1[2] += c_b;

				this->AmbientLight2[0] += c_r;
				this->AmbientLight2[1] += c_g;
				this->AmbientLight2[2] += c_b;
			}
		}
		
		break;
	case false:
		for (int i = 0; i < 3; ++i)
		{
			if (AmbientLight1[i] > 0 && AmbientLight2[i] > 0)
			{
				this->AmbientLight1[0] -= c_r;
				this->AmbientLight1[1] -= c_g;
				this->AmbientLight1[2] -= c_b;

				this->AmbientLight2[0] -= c_r;
				this->AmbientLight2[1] -= c_g;
				this->AmbientLight2[2] -= c_b;
			}
		}
	
		break;
	}
}
void LightObject::ChangeDiffuseLightRGBA(bool updown)
{
	switch (updown)
	{
	case true:
		for (int i = 0; i < 3; ++i)
		{
			if (DiffuseLight1[i] < 1 && DiffuseLight2[i] < 1)
			{
				this->DiffuseLight1[0] += c_r;
				this->DiffuseLight1[1] += c_g;
				this->DiffuseLight1[2] += c_b;

				this->DiffuseLight2[0] += c_r;
				this->DiffuseLight2[1] += c_g;
				this->DiffuseLight2[2] += c_b;
			}
		}
	
		break;
	case false:
		for (int i = 0; i < 3; ++i)
		{
			if (DiffuseLight1[i] > 0 && DiffuseLight2[i] >0)
			{
				this->DiffuseLight1[0] -= c_r;
				this->DiffuseLight1[1] -= c_g;
				this->DiffuseLight1[2] -= c_b;

				this->DiffuseLight2[0] -= c_r;
				this->DiffuseLight2[1] -= c_g;
				this->DiffuseLight2[2] -= c_b;
			}
		}
		
		break;
	}
}
void LightObject::ChangeSpecularLightRGBA(bool updown)
{
	switch (updown)
	{
	case true:
		for (int i = 0; i < 3; ++i)
		{
			if (SpecularLight1[i] <1 && SpecularLight2[i]  <1)
			{
				this->SpecularLight1[0] += c_r;
				this->SpecularLight1[1] += c_g;
				this->SpecularLight1[2] += c_b;

				this->SpecularLight2[0] += c_r;
				this->SpecularLight2[1] += c_g;
				this->SpecularLight2[2] += c_b;
			}
		}
		
		break;
	case false:
		for (int i = 0; i < 3; ++i)
		{
			if (SpecularLight1[i] > 0 && SpecularLight2[i] > 0)
			{
				this->SpecularLight1[0] -= c_r;
				this->SpecularLight1[1] -= c_g;
				this->SpecularLight1[2] -= c_b;

				this->SpecularLight2[0] -= c_r;
				this->SpecularLight2[1] -= c_g;
				this->SpecularLight2[2] -= c_b;
			}
		}
		break;
	}
}

void LightObject::OnOffLight1()
{
	this->light_1 = !this->light_1;
}
void LightObject::OnOffLight2()
{
	this->light_2 = !this->light_2;
}

