#include "stdafx.h"
#include "Basic.h"
#include "Menu.h"

Menu::Menu()
{
	up_sp = Select_Part(WindowHeight / 3, 3, 0);
	middle_sp = Select_Part(0.f, 3, 1);
	down_sp = Select_Part(-WindowHeight / 3, 3, 2);
	PlaySound(TEXT(TITLE_SOUND_NAME), NULL, SND_ASYNC | SND_LOOP);
}
Menu::~Menu()
{

}

void Menu::DrawMenu()
{
	glPushMatrix();
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		//원근 투영
		gluPerspective(60.f, WindowWidth / WindowHeight, 1.f, 10000.f);
		glTranslatef(0.0f, 0.0f, -WindowWidth / 2);
		glMatrixMode(GL_MODELVIEW); // 모델행렬 이거 안해서 그랬음..
		glLoadIdentity();

		glPushMatrix();
		{
			//glRotatef(30.f, 1.f, 0.f, 0.f);
			//스팟라이트 설정
			glEnable(GL_LIGHTING);
			glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT0, GL_SPECULAR, spc);
			glLightfv(GL_LIGHT0, GL_POSITION, title_lightpos);
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 120.0);
			glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 60.0);
			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_dir);
			glEnable(GL_LIGHT0);

			glEnable(GL_COLOR_MATERIAL);
			glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
			glMaterialfv(GL_FRONT, GL_SPECULAR, spc);
			glMateriali(GL_FRONT, GL_SHININESS, 64);
		}
		glPopMatrix();


		up_sp.Draw();
		middle_sp.Draw();
		down_sp.Draw();
	}
	glPopMatrix();
}