#include "stdafx.h"
#include "BossBullet.h"
#include "CollisionBox.h"

class Boss{
private:
	float x, y, z;
	float m_x, m_y, m_z;
	float size;
	int bullet_num; //�ѹ��� �߻��ϴ� �Ѿ� ���� 
	GLfloat shot_time;  
	GLfloat shot_cycle; //�Ѿ��� �߻��ϴ� �ֱ�
	int bullet_count;
	Collisionbox m_bossbox;
public:
	BossBullet* bullets[MAX_BOSS_BULLET_NUM];
	Boss(){}
	Boss(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _size, GLfloat cycle, int num):x { _x }, y{ _y }, z{ _z }, size{ _size }
	{
		m_bossbox = Collisionbox(x, y, z, size);
		shot_time = 0.f;
		bullet_count = 0;
		shot_cycle = cycle;
		bullet_num = num;
	}
	Collisionbox GetBossBox()
	{
		return m_bossbox;
	}
	void Draw() 
	{
		glPushMatrix();
		{
			glColor3f(0.f, 0.f, 0.2f);
			glTranslatef(x, 0.f, z);

			//�ص�
			glPushMatrix();
			{
				glTranslatef(0.f, size / 2.f, 0.f);
				glutSolidCube(size);
			}
			glPopMatrix();

			//�߰�
			glPushMatrix();
			{
				glTranslatef(0.f, size * 1.25f, 0.f);
				glutSolidCube(size / 2.f);
			}
			glPopMatrix();

			//ž 
			glPushMatrix();
			{
				glTranslatef(0.f, size * 1.6f, 0.f);
				glutSolidCube(size / 3.f);
			}
			glPopMatrix();

			//���� 
			glPushMatrix();
			{
				glColor3f(1.f, 0.f, 0.f);
				glTranslatef(0.f, size * 1.6f, 0.f);
				glPushMatrix();
				{
					glTranslatef(size / 6.f, 0.f, 0.f);
					glutSolidSphere(size / 20.f, 50, 50);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glTranslatef(-size / 6.f, 0.f, 0.f);
					glutSolidSphere(size / 20.f, 50, 50);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glTranslatef(0.f, 0.f, size / 6.f);
					glutSolidSphere(size / 20.f, 50, 50);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glTranslatef(0.f, 0.f, -size / 6.f);
					glutSolidSphere(size / 20.f, 50, 50);
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();

		for (int i = 0; i < MAX_BOSS_BULLET_NUM; i++) 
		{
			if(bullets[i] != NULL)
				bullets[i]->Draw();
		}
	}
	void Update()
	{
		shot_time += 0.1f;
		for (int i = 0; i < MAX_BOSS_BULLET_NUM; i++) {
			if (bullets[i] != NULL)
			{
				bullets[i]->Update();
			}
		}

		//���� �Ѿ� �ֱ⸶�� �Ѿ��� �߻��ϰ� �ʱ�ȭ 
		if (shot_time > shot_cycle) 
		{
			Shot();
			shot_time = 0;
			bullet_num++;
		}
		m_bossbox.UpdateBox(x, y, z);
	}


	void Shot() {
		GLfloat rotate = 0.f;
		GLfloat radius = 100.f;

		//���� ������ŭ ������� �Ѿ� �߻� 
		for (int i = 0; i < bullet_num; i++) {
			GLfloat bullet_x = x + radius * cos(rotate * PI / 180.f);
			GLfloat bullet_z = z + radius * sin(rotate * PI / 180.f);
			GLfloat bullet_y = 50.f;
			
			GLfloat bullet_vx = (bullet_x - x) / sqrt(pow(bullet_x - x, 2) + pow(bullet_z - z, 2));
			GLfloat bullet_vz = (bullet_z - z) / sqrt(pow(bullet_z - z, 2) + pow(bullet_x - x, 2));

			
			BossBullet *new_bullet = new BossBullet(bullet_x, bullet_y, bullet_z, 50.f, 20.f, bullet_vx, bullet_vz);

			bullets[bullet_count] = new_bullet;

			rotate += 360.f / static_cast<GLfloat>(bullet_num - 1);
			bullet_count++;

		}

		//�Ѿ� ������ �ִ� �Ѿ� ������ �Ѿ�� �ʱ�ȭ 
		if (bullet_count >= MAX_BOSS_BULLET_NUM - bullet_num) {
			bullet_count = 0;
		}
	}

	

};