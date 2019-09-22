#pragma once
#include "stdafx.h"
#include "Head.h"
#include "Body.h"
#include "Leg.h"

//Ÿ��Ʋ ȭ�鿡�� ������ �����ϰ� �ϴ� Ŭ���� 
class Select_Part
{
public:
	int part_num; //������ ���� 
	int select_part; //������ �����ϴ� ���� ��
	GLfloat rotate = 0; //ȸ�� ���� 
	GLfloat y; //���� ��ġ  
	GLfloat min_rotate; //�ּ� ȸ���� 
	GLfloat max_rotate; //�ִ� ȸ���� 
	int select_kind = 0; //���, �ٵ�, �ٸ�, ��, ���� �� ���� 
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

			//������ ���� 
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

			//�������� 
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

			//��� ���� 
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

	//������ �����ϴ� �Լ� 
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
		//�������� ����
		if (rotate == max_rotate)
			return 2;
		//��� ���� ���� 
		if (rotate == 0.f)
			return 3;
		//������ ���� ���� 
		if (rotate == min_rotate)
			return 1;
	}
};