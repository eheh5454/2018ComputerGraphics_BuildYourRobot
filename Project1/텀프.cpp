#include "stdafx.h"
#include "Bullet.h"
#include "Robot.h"
#include "Camera.h"
#include "Map.h"
#include "Menu.h"
#include "Enermy.h"
#include "UI.h"
#include "Boss.h"
#include "LightObject.h"
#include "CollisionBox.h"
#include "Title.h"
#include "Particle.h"

GameState now_game_state;

Menu* g_menu;
UI* g_ui;
Title g_title;
Map* g_map;
Camera* g_camera;

Bullet* m_bullet[MAX_BULLET];
Robot* m_robot;
Enermy* m_enermy[MAX_ENERMY];//(400, 0, 400, 50);
Boss m_boss(500, 0, 500, 200, 10.f, 10.f);
XYZPOS all_pos[MAX_OBJECT];
LightObject g_light(WindowWidth);
Particle* m_particle[MAX_OBJECT];


GLfloat first_x;
int select_kinds;
bool left_button;
bool right_button;

int boss_hp = 500;
int dead_enermy_cnt = 0;
bool boss_stage;
bool s_or_g;
bool attack_sword;
float sword_angle;
bool cheat;

float g_time = 50.f;

//캐릭터
float c_x;
float c_y;
float c_z;
float speed = 5;

GLfloat spc[4] = { 1.f,1.f,1.f,1.f };

GLvoid Reshape(int w, int h);
GLvoid drawScene(GLvoid);
void TimerFunction(int value);
void Keyboard(unsigned char key, int x, int y);
void Idle(void);
void InitStat();
void ShapeColor();
void SpecialKeyboard(int key, int x, int y);
void TimerFunction(int value);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
bool Collision_Check(Collisionbox a, Collisionbox b);

//================================== 사용자 정의 함수
void InitStat()
{
	std::random_device rd;
	std::default_random_engine dre{ rd() };

	std::uniform_real_distribution<float> ranpos{ -WindowHeight,WindowHeight };
	cheat = false;
	boss_stage = false;
	sword_angle = 180;
	now_game_state = title_game;
	s_or_g = false;
	attack_sword = false;
	g_ui = new UI();
	g_menu = new Menu();
	g_map = new Map();
	g_camera = new Camera();
	m_robot = new Robot(0,10,0,HERO_SIZE);
	for (int i = 0; i < MAX_BULLET; ++i)
	{
		m_bullet[i] = nullptr;
	}
	for (int i = 0; i < MAX_ENERMY; ++i)
	{
		m_enermy[i] = new Enermy(ranpos(dre), 0, ranpos(dre), 50);
	}
	right_button = false;
	c_x = 0.f; c_y = 0.f; c_z = 0.f;
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		m_particle[i] = nullptr;
		all_pos[i].x = NULL, all_pos[i].y = NULL, all_pos[i].z = NULL;
	}
	g_light.SetAmbientLightRGBA(0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);
	g_light.SetDiffuseLightRGBA(1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f);
}
void ShapeColor()
{
	std::random_device rd;
	std::default_random_engine dre{ rd() };

	std::uniform_real_distribution<float> cor{ 0.0,1.0 };
	std::uniform_int_distribution<int> dist1{ 0,2 };
	float r1 = cor(dre);
	float g1 = cor(dre);
	float b1 = cor(dre);
	int randcor = dist1(dre);
	glColor3f(r1, g1, b1);
	if (randcor == 0) {
		r1 += 0.05f;
	}
	else if (randcor == 1) {
		g1 += 0.05f;
	}
	else if (randcor == 2) {
		b1 += 0.05f;
	}
}
void CheckCollison()
{
	std::random_device rd;
	std::default_random_engine dre{ rd() };

	std::uniform_real_distribution<float> ranpos{ -WindowHeight,WindowHeight };
	for (int i = 0; i < MAX_BULLET; ++i)
	{
		for (int j = 0; j < MAX_ENERMY; ++j)
		{
			if (m_bullet[i] != nullptr && m_enermy[j] != nullptr)
			{
				if (Collision_Check(m_bullet[i]->GetPlayerBulletBox(), m_enermy[j]->GetEnermyBox()))
				{
					if(m_particle[i] == nullptr)
						m_particle[i] = new Particle(m_enermy[j]->GetX(), m_enermy[j]->GetY()+20, m_enermy[j]->GetZ(), 30);
					m_bullet[i] = nullptr, m_enermy[j] = nullptr;
					++dead_enermy_cnt;
					if(!boss_stage)
						m_enermy[j] = new Enermy(ranpos(dre), 0, ranpos(dre), 50);
				}
			}
		}
	}
	for (int i = 0; i < MAX_ENERMY; ++i)
	{
		if (m_enermy[i] != nullptr)
		{
			if (attack_sword)
			{
				if (Collision_Check(m_robot->GetPlayerAttackBox(), m_enermy[i]->GetEnermyBox()))
				{
					m_enermy[i] = nullptr;
				}
			}
			else
			{
				if (Collision_Check(m_robot->GetPlayerBox(), m_enermy[i]->GetEnermyBox()))
				{
					m_enermy[i] = nullptr;
					if (!cheat)
					{
						hp -= 10;
						g_ui->SetHpBar();
					}
				}
			}
		}
	}
	if (boss_stage)
	{
		for (int i = 0; i < MAX_BULLET; ++i)
		{
			if (m_bullet[i] != nullptr)
			{
				if (Collision_Check(m_bullet[i]->GetPlayerBulletBox(), m_boss.GetBossBox()))
				{
					m_bullet[i] = nullptr;
					boss_hp -= 10;
				}
			}
		}
		for (int i = 0; i < MAX_BOSS_BULLET_NUM; ++i)
		{
			if (m_boss.bullets[i] != NULL)
			{
				if (Collision_Check(m_robot->GetPlayerBox(), m_boss.bullets[i]->GetBox()))
				{
					hp -= 1;
					g_ui->SetHpBar();
				}
			}
		}
	}
}
bool Collision_Check(Collisionbox a, Collisionbox b)
{
	GLfloat left_a = a.x - a.size / 2;
	GLfloat right_a = a.x + a.size / 2;
	GLfloat top_a = a.z - a.size / 2;
	GLfloat bottom_a = a.z + a.size / 2;

	GLfloat left_b = b.x - b.size / 2;
	GLfloat right_b = b.x + b.size / 2;
	GLfloat top_b = b.z - b.size / 2;
	GLfloat bottom_b = b.z + b.size / 2;

	if (left_a >= right_b)
		return false;
	if (right_a <= left_b)
		return false;
	if (top_a >= bottom_b)
		return false;
	if (bottom_a <= top_b)
		return false;

	return true;
}
void UpdatePos()
{
	all_pos[0].x = m_robot->GetX(), all_pos[0].y = m_robot->GetY(), all_pos[0].z = m_robot->GetZ();
	g_ui->UpdateMiniMap(0, all_pos[0]);
	for (int i = 1; i < MAX_ENERMY+1;)
	{
		for (int j = 0; j < MAX_ENERMY; ++j)
		{
			if (m_enermy[j] != nullptr)
			{
				all_pos[i].x = m_enermy[j]->GetX(), all_pos[i].y = NULL, all_pos[i].z = m_enermy[j]->GetZ();
				g_ui->UpdateMiniMap(i, all_pos[i]);
				++i;
			}
			else
			{
				all_pos[i].x = NULL, all_pos[i].y = NULL, all_pos[i].z = NULL;
				g_ui->UpdateMiniMap(i, all_pos[i]);
				++i;
			}
		}
	}
	for (int i = MAX_ENERMY+1; i < MAX_BULLET+MAX_ENERMY + 1;)
	{
		for (int j = 0; j < MAX_BULLET; ++j)
		{
			if (m_bullet[j] != nullptr)
			{
				all_pos[i].x = m_bullet[j]->GetX(), all_pos[i].y = NULL, all_pos[i].z = m_bullet[j]->GetZ();
				g_ui->UpdateMiniMap(i, all_pos[i]);
				++i;
			}
			else
			{
				all_pos[i].x = NULL, all_pos[i].y = NULL, all_pos[i].z = NULL;
				g_ui->UpdateMiniMap(i, all_pos[i]);
				++i;
			}
		}
	}
}
//================================== gl함수
void Idle(void)
{
	
}
void Keyboard(unsigned char key, int x, int y)
{
	switch (now_game_state)
	{
	case select_model:
		if (key == ' ')
		{
			now_game_state = start_game;
			player_view = 1;
			m_robot->Select_Parts(g_menu->up_sp.Get_Selected_Part(), g_menu->middle_sp.Get_Selected_Part(), g_menu->down_sp.Get_Selected_Part());
			PlaySound(TEXT(START_SOUND_NAME), NULL, SND_ASYNC && SND_LOOP && SND_NOSTOP);
		}
		break;
	case start_game:
		switch (key)
		{
		case '`':
			cheat = !cheat;
			break;
		case '=':
			boss_stage = true;
			break;
		case '1':
			s_or_g = false;
			break;
		case '2':
			s_or_g = true;
			break;
		case 'v':
		case 'V':
			++player_view;
			if (player_view == 3)
				player_view = 1;
			break;
		case 'a':
			c_x -= speed * cos((-g_camera->GetCameraXAngle())* DEG2RAD);
			c_z -= speed * sin((-g_camera->GetCameraXAngle())* DEG2RAD);
			m_robot->KeyUpdate(c_x, c_z);
			break;
		case 'd':
			c_x += speed * cos((-g_camera->GetCameraXAngle())* DEG2RAD);
			c_z += speed * sin((-g_camera->GetCameraXAngle())* DEG2RAD);
			m_robot->KeyUpdate(c_x, c_z);
			break;
		case 'y':
			c_y -= 5.f;
			break;
		case 'Y':
			c_y += 5.f;
			break;
		case 'w':
			c_x += speed * cos((-g_camera->GetCameraXAngle() - 90)* DEG2RAD);
			c_z += speed * sin((-g_camera->GetCameraXAngle() - 90)* DEG2RAD);
			m_robot->KeyUpdate(c_x, c_z);
			break;
		case 's':
			c_x -= speed * cos((-g_camera->GetCameraXAngle() - 90)* DEG2RAD);
			c_z -= speed * sin((-g_camera->GetCameraXAngle() - 90)* DEG2RAD);
			m_robot->KeyUpdate(c_x, c_z);
			break;
		}
		break;
	case win_game:
	case lose_game:
		break;
	}
	Reshape(WindowWidth, WindowHeight);
	glutPostRedisplay();
}
void SpecialKeyboard(int key, int x, int y)
{
	/*if (now_game_state == start_game) {
		switch (key) {
		case GLUT_KEY_LEFT:
			testbot.Change_State_left();
			break;
		case GLUT_KEY_RIGHT:
			testbot.Change_State_right();
			break;
		case GLUT_KEY_UP:
			testbot.Change_State_up();
			break;
		case GLUT_KEY_DOWN:
			testbot.Change_State_down();
			break;
		}
	}*/
}
void TimerFunction(int value)
{
	switch (now_game_state)
	{
	case select_model:
		break;
	case start_game:
		CheckCollison();
		for (int i = 0; i < MAX_BULLET; ++i) // 총알 업뎃
		{
			if (m_bullet[i] != nullptr)
			{
				m_bullet[i]->UpdateBullet();
				if (m_bullet[i]->GetOutOfMap())
					m_bullet[i] = nullptr;
			}		
		}
		for (int i = 0; i < MAX_ENERMY; ++i) // 총알 업뎃
		{
			if (m_enermy[i] != nullptr)
			{
				m_enermy[i]->Update(c_x, c_y, c_z);
			}
		}
		if (attack_sword)
		{
			sword_angle -= 10.f;
			m_robot->AttackUpdate(sword_angle);
			if (sword_angle <= 0)
			{
				sword_angle = 0;
				attack_sword = false;
			}
		}
		m_boss.Update();
		UpdatePos();
		if (boss_hp <= 0)
			now_game_state = win_game;
		if (hp <= 0)
			now_game_state = lose_game;
		for (int i = 0; i < MAX_OBJECT; ++i)
		{
			if (m_particle[i] != nullptr)
			{
				m_particle[i]->Update();
				if (m_particle[i]->EndParticle())
				{
					m_particle[i] = nullptr;
				}
			}
			
		}
		break;
	case win_game:
	case lose_game:
		exit(1);
		break;
	}
	
	if (dead_enermy_cnt >= 100)
	{
		boss_stage = true;
	}

	glutPostRedisplay();
	glutTimerFunc(g_time, TimerFunction, 1);
}
void Mouse(int button, int state, int x, int y)
{
	bool limit_click = false;
	bool what_view;
	switch (now_game_state)
	{
	case title_game:
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			now_game_state = select_model;
		break;
	case select_model:
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			left_button = true;
			first_x = static_cast<float>(x - WindowWidth / 2);
			//마우스 위치에 따라 머리, 몸통, 다리 선택을 하도록 함 
			if (-(y - WindowHeight / 2) > WindowHeight / 4.f)
				select_kinds = 0;
			else if (-(y - WindowHeight / 2) <= WindowHeight / 4.f &&
				-(y - WindowHeight / 2) >= -WindowHeight / 4.f)
				select_kinds = 1;
			else if (-(y - WindowHeight / 2) < -WindowHeight / 4.f)
				select_kinds = 2;
		}
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			left_button = false;
			g_menu->up_sp.AdjustRotate();
			g_menu->middle_sp.AdjustRotate();
			g_menu->down_sp.AdjustRotate();
		}
		break;
	case start_game:
		if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (player_view == 1 || player_view == 2))
		{
			if (!s_or_g)
			{
				for (int i = 0; i < MAX_BULLET; ++i)
				{
					if (m_bullet[i] == nullptr)
					{
						if (player_view == 1)
						{
							what_view = true;
						}
						else
						{
							what_view = false;
						}
						PlaySound(TEXT(GUN_SOUND_NAME), NULL, SND_ASYNC);
						m_bullet[i] = new Bullet(HERO_SIZE, c_x, c_y, c_z, g_camera->GetCameraXAngle(), g_camera->GetCameraYAngle(), what_view);
						break;
					}
				}
			}
			else
			{
				attack_sword = true;
				sword_angle = 180.f;
				PlaySound(TEXT(SWORD_SOUND_NAME), NULL, SND_ASYNC);
			}
			
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{

		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //줌인용
		{
			right_button = true;
		}
		else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
		{
			right_button = false;
		}
		break;
	case win_game:
	case lose_game:
		break;
	}
}
void Motion(int x, int y)
{
	GLfloat rotate_value = 0.f;
	switch (now_game_state)
	{
	case select_model:
		if (left_button == true) {
			if (x - WindowWidth / 2 < first_x) {
				rotate_value += ((x - WindowWidth / 2) - first_x) / 2.f;
				switch (select_kinds) {
				case 0:
					g_menu->up_sp.rotate += rotate_value;
					break;
				case 1:
					g_menu->middle_sp.rotate += rotate_value;
					break;
				case 2:
					g_menu->down_sp.rotate += rotate_value;
					break;
				}


			}
			if (x - WindowWidth / 2 > first_x) {
				rotate_value += ((x - WindowWidth / 2) - first_x) / 2.f;
				switch (select_kinds) {
				case 0:
					g_menu->up_sp.rotate += rotate_value;
					break;
				case 1:
					g_menu->middle_sp.rotate += rotate_value;
					break;
				case 2:
					g_menu->down_sp.rotate += rotate_value;
					break;
				}
			}
			first_x = static_cast<float>(x - WindowWidth / 2);
		}
		break;
	case start_game:
		g_camera->SetCenX(x);
		g_camera->SetCenY(y);
		g_camera->CalculateView(x, y);
		break;
	case win_game:
	case lose_game:
		break;
	}
}
GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, w / h, 1.f, 10000.f);
	glMatrixMode(GL_MODELVIEW);
}
GLvoid drawScene(GLvoid)
{
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glViewport(0, 0, WindowWidth, WindowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, WindowWidth / WindowHeight, 1.f, 10000.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	switch (now_game_state)
	{
	case title_game:
		glEnable(GL_DEPTH_TEST);
		g_title.Draw();
		break;
	case select_model:
		glEnable(GL_DEPTH_TEST);
		g_menu->DrawMenu();
		break;
	case start_game:
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);

		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, spc);
		glMateriali(GL_FRONT, GL_SHININESS, 68);

		g_light.DrawLightObject();

		g_camera->UpdateView(right_button, c_x, c_y, c_z, 100);
		glPushMatrix();//플레이어
		{
			glTranslatef(c_x, c_y+70, c_z);
			glRotatef(g_camera->GetCameraXAngle(), 0, 1, 0);
			m_robot->DrawRobot();
		}
		glPopMatrix();
		glPushMatrix();//맵
		{
			g_map->Draw();
		}
		glPopMatrix();

		glPushMatrix();//총알
		{
			ShapeColor();
			for (int i = 0; i < MAX_BULLET; ++i)
			{
				if (m_bullet[i] != nullptr)
					m_bullet[i]->DrawBullet();
			}
		}
		glPopMatrix();

		glPushMatrix();//따까리들
		{
			for (int i = 0; i < MAX_ENERMY; ++i)
			{
				if (m_enermy[i] != nullptr)
					m_enermy[i]->Draw();
			}
		}
		glPopMatrix();

		glPushMatrix();
		{
			if(boss_stage)
				m_boss.Draw();
		}
		glPopMatrix();

		for (int i = 0; i < MAX_OBJECT; ++i)
		{
			if (m_particle[i] != nullptr)
			{
				m_particle[i]->DrawParticle();
			}
		}
		glPushMatrix();//미니맵 크로스헤어 hp등
		{
			g_ui->DrawGameState();
		}
		glPopMatrix();


		
		break;
	case win_game:
		break;
	case lose_game:
		break;
	}
	
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	InitStat();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutCreateWindow("컴그팀");
	glutPassiveMotionFunc(Motion);
	glutMouseFunc(Mouse);
	glutIdleFunc(Idle);//나중에 프레임 고정용 구글링에선 여기서 처리하라 했음 아님 말고~
	glutMotionFunc(Motion);
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutReshapeFunc(Reshape);
	glutTimerFunc(g_time, TimerFunction, 1);
	glutMainLoop();
}