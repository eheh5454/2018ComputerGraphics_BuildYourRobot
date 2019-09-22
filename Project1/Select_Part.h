#pragma once
#include "stdafx.h"
#include "Head.h"
#include "Body.h"
#include "Leg.h"

//타이틀 화면에서 파츠를 선택하게 하는 클래스 
class Select_Part
{
public:
	int part_num; //파츠의 개수 
	int select_part; //파츠를 선택하는 변수 ㅅ
	GLfloat rotate = 0; //회전 각도 
	GLfloat y; //축의 위치  
	GLfloat min_rotate; //최소 회전각 
	GLfloat max_rotate; //최대 회전각 
	int select_kind = 0; //헤드, 바디, 다리, 팔, 날개 중 선택 
	Head *head;
	Body *body;
	Leg *leg;

	Select_Part() {}
	Select_Part(GLfloat _y, GLfloat num, int kind) :y(_y), part_num(num), select_kind(kind)
	{
		min_rotate = -90.f;
		max_rotate = 90.f;
		switch (select_kind)
		{
		case 0:
			head = new Head(50.f);
			break;
		case 1:
			body = new Body(50.f);
			break;
		case 2:
			leg = new Leg(50.f);
			break;
		}
	}

	void Draw()
	{
		glPushMatrix();
		{
			glTranslatef(0.f, y, -100.f);
			glRotatef(rotate, 0.f, 1.f, 0.f);

			//오른쪽 파츠 
			glPushMatrix();
			{
				glColor3f(1.f, 0.f, 0.f);
				glTranslatef(200.f, 0.f, 0.f);
				glRotatef(90.f, 0.f, 1.f, 0.f);
				switch (select_kind)
				{
				case 0:
					glPushMatrix();
					{
						glRotatef(180.f, 0.f, 1.f, 0.f);
						head->Draw(1);
					}
					glPopMatrix();
					break;
				case 1:
					glPushMatrix();
					{
						glRotatef(180.f, 0.f, 1.f, 0.f);
						body->Draw(1);
					}
					glPopMatrix();
					break;
				case 2:
					glPushMatrix();
					{
						leg->Draw(1);
					}
					glPopMatrix();
					break;
				}
			}
			glPopMatrix();

			//왼쪽파츠 
			glPushMatrix();
			{
				glColor3f(0.f, 1.f, 0.f);
				glTranslatef(-200.f, 0.f, 0.f);
				glRotatef(-90.f, 0.f, 1.f, 0.f);
				switch (select_kind)
				{
				case 0:
					glPushMatrix();
					{
						glRotatef(180.f, 0.f, 1.f, 0.f);
						head->Draw(2);
					}
					glPopMatrix();
					break;
				case 1:
					glPushMatrix();
					{
						glRotatef(180.f, 0.f, 1.f, 0.f);
						body->Draw(2);
					}
					glPopMatrix();
					break;
				case 2:
					glPushMatrix();
					{
						leg->Draw(2);
					}
					glPopMatrix();
					break;
				}
			}
			glPopMatrix();

			//가운데 파츠 
			glPushMatrix();
			{
				glColor3f(0.f, 0.f, 1.f);
				glTranslatef(0.f, 0.f, 200.f);
				switch (select_kind)
				{
				case 0:
					glPushMatrix();
					{
						glRotatef(180.f, 0.f, 1.f, 0.f);
						head->Draw(3);
					}
					glPopMatrix();
					break;
				case 1:
					glPushMatrix();
					{
						glRotatef(180.f, 0.f, 1.f, 0.f);
						body->Draw(3);
					}
					glPopMatrix();
					break;
				case 2:
					glPushMatrix();
					{
						leg->Draw(3);
					}
					glPopMatrix();
					break;
				}
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	//각도를 보정하는 함수 
	void AdjustRotate() {
		if (rotate < -50.f) {
			rotate = min_rotate;
		}
		if (rotate >= -50.f && rotate < 50.f) {
			rotate = 0.f;
		}
		if (rotate >= 50.f) {
			rotate = max_rotate;
		}
	}

	int Get_Selected_Part() {
		//왼쪽파츠 선택
		if (rotate == max_rotate)
			return 2;
		//가운데 파츠 선택 
		if (rotate == 0.f)
			return 3;
		//오른쪽 파츠 선택 
		if (rotate == min_rotate)
			return 1;
	}
};