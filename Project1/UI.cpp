#include "stdafx.h"
#include "UI.h"

UI::UI()
{
	InitUi();
}
UI::~UI()
{

}

void UI::InitUi()
{
	hp_bar.x = hp * 10;
	for (int i = 0; i < 4; ++i)
	{
		cross[i].x = 0, cross[i].y = 0, cross[i].z = 0;
	}
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		all_object[i].x =NULL, all_object[i].y =NULL, all_object[i].z = NULL;
	}
}
void UI::DrawHpBar()
{
	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1.f, 0.f, 0.f, 0.5);
		glTranslatef(-WindowWidth / 3, WindowHeight / 3, 0);
		glBegin(GL_QUADS);
		{
			glVertex2f(0, 0);
			glVertex2f(0, -50);
			////////////////////////////////
			glVertex2f(hp_bar.x, -50);
			glVertex2f(hp_bar.x, 0);
		}
		glEnd();
	}
	glPopMatrix();
}
void UI::DrawMiniMap()
{
	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1.f, 0.f, 1.f, 0.3);
		glPushMatrix();
		{
			glTranslatef(-WindowWidth / 3, -WindowHeight / 3, 0);
			glBegin(GL_QUADS);
			{
				glVertex2f(-WindowWidth / 8, WindowWidth / 8);
				glVertex2f(-WindowWidth / 8, -WindowWidth / 8);
				////////////////////////////////
				glVertex2f(WindowWidth / 8, -WindowWidth / 8);
				glVertex2f(WindowWidth / 8, WindowWidth / 8);
			}
			glEnd();
		}
		glPopMatrix();
		for (int i = 0; i < MAX_OBJECT; ++i)
		{
			if (all_object[i].x != NULL && all_object[i].z != NULL)
			{
				glPushMatrix();
				{
					if (i == 0)
					{
						glColor4f(0.f, 0.f, 1.f, 1.f);
						glPointSize(30.f);
					}
					else if (i > 0 && i < MAX_ENERMY + 1)
					{
						glColor4f(1.f, 0.f, 0.f, 1.f);
						glPointSize(20.f);
					}
					else if (i >= MAX_ENERMY + 1 && i < MAX_BULLET + MAX_ENERMY + 1)
					{
						glColor4f(0.f, 1.f, 0.f, 1.f);
						glPointSize(10.f);
					}
					glTranslatef(-WindowWidth / 3, -WindowHeight / 3, 0);
					glBegin(GL_POINTS);
					{
						glVertex2f(-all_object[i].x / 8.f, all_object[i].z / 8.f);
					}
					glEnd();
				}
				glPopMatrix();
			}
			else
				continue;
		}
		
	}
	glPopMatrix();
}
void UI::DrawCrossHair()
{
	glPushMatrix();
	{
		glLineWidth(5.f);
		glColor3f(1, 0, 0);
		glTranslatef(0.f, -50.f, 0.f);
		glBegin(GL_LINES);//위
		{
			glVertex2f(cross[0].x, cross[0].y);
			glVertex2f(cross[0].x, cross[0].y + 30);

			glVertex2f(cross[1].x, cross[1].y);
			glVertex2f(cross[1].x + 30, cross[1].y);

			glVertex2f(cross[2].x, cross[2].y);
			glVertex2f(cross[2].x, cross[2].y - 30);

			glVertex2f(cross[3].x, cross[3].y);
			glVertex2f(cross[3].x - 30, cross[3].y);
		}
		glEnd();
		glLineWidth(1.f);
	}
	glPopMatrix();
}
void UI::DrawGameState() //전체 그리기
{
	glPushMatrix();
	{
		glViewport(0, 0, WindowWidth, WindowHeight);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-WindowWidth /2, WindowWidth / 2, - WindowHeight / 2, WindowHeight/2, -WindowWidth/2, WindowWidth/2);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_NORMALIZE);

		if(player_view == 1)
			DrawCrossHair();
		DrawHpBar();
		DrawMiniMap();

	}
	glPopMatrix();
}
void UI::SetCross(bool shoot)
{
	if (shoot)
	{
		cross[0].y += 10; //위
		cross[1].x += 10;//오른
		cross[2].y -= 10;//아래
		cross[3].x -= 10;//왼
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			cross[i].x = 0, cross[i].y = 0, cross[i].z = 0;
		}
	}
}
void UI::SetHpBar() //hp에 비례해서 오른쪽 끝점의 위치를 바꾸게 한다.
{
	hp_bar.x = hp * 10;
}
void UI::UpdateMiniMap(int i,XYZPOS pos)
{
	this->all_object[i] = pos;
}