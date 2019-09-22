#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
{
	InitCamera();
}
Camera::~Camera()
{

}

void Camera::InitCamera()
{
	//일단 대기 라이브러리 적용 할거 너무 많으면 그때 지울거임
	//c_position = glm::vec3(0.f, 0.f, 3.f);
	//c_target = glm::vec3(0.f, 0.f, 0.f);
	//c_direction = glm::normalize(c_position - c_target);

	//up = glm::vec3(0.f,1.f,0.f); // 위쪽벡터
	//c_right = glm::normalize(glm::cross(up,c_direction));
	//c_up = glm::cross(c_direction,c_right);
	
	c_x_angle = 0, c_y_angle = -90;
	v_x = 0, v_y = 0, v_z = -10000;
	camera_distance = 100;
	center_x = 0, center_y = 0;
	mouse_sens = 30;
}
void Camera::ChangeMouseSens(bool updown)
{
	switch (updown)
	{
	case true:
		mouse_sens += 1.f;
		break;
	case false:
		mouse_sens -= 1.f;
		break;
	}
}
float Camera::GetCameraXAngle()
{
	return c_x_angle;
}
float Camera::GetCameraYAngle()
{
	return c_y_angle;
}
float Camera::GetViewX()
{
	return v_x;
}
float Camera::GetViewY()
{
	return v_y;
}
float Camera::GetViewZ()
{
	return v_z;
}
float Camera::GetCameraX()
{
	return camera_x;
}
float Camera::GetCameraY()
{
	return camera_y;
}
float Camera::GetCameraZ()
{
	return camera_z;
}
float Camera::GetCameraDistance()
{
	return camera_distance;
}
int Camera::GetCenX()
{
	return cen_x;
}
int Camera::GetCenY()
{
	return cen_y;
}

void Camera::SetCameraXAngle(float angle)
{
	this->c_x_angle = angle;
}
void Camera::SetCameraYAngle(float angle)
{
	this->c_y_angle = angle;
}
void Camera::SetViewX(float x)
{
	this->v_x = x;
}
void Camera::SetViewY(float y)
{
	this->v_y = y;
}
void Camera::SetViewZ(float z)
{
	this->v_z = z;
}
void Camera::SetCameraX(float x)
{
	this->camera_x = x;
}
void Camera::SetCameraY(float y)
{
	this->camera_y = y;
}
void Camera::SetCameraZ(float z)
{
	this->camera_z = z;
}
void Camera::SetCameraDistance(float dis)
{
	this->camera_distance = dis;
}
void Camera::SetCenX(int x)
{
	this->cen_x = (WindowWidth / 2) - x;
}
void Camera::SetCenY(int y)
{
	this->cen_y = (WindowHeight / 2) - y;
}

void Camera::UpdateView(bool right_button, float x, float y, float z, float character_height)
{
	switch (player_view)
	{
	case 0://일반 화면
		glTranslatef(0.f, 0.f, -WindowWidth / 2);
		gluLookAt(0.f, 0.f, 0.f, 0.f, 0.f, -1.f, 0.f, 1.f, 0.f);
		break;
	case 1://1인칭
		if (!right_button)
		{
			gluLookAt(x, y + character_height, z, x + v_x, y + v_y + character_height, z + v_z, 0.f, 1.f, 0.f);
		}
		else
		{
			glTranslatef(0.f, 0.f, -WindowWidth / 2);
			gluLookAt(x + v_x, y + character_height, z + v_z, (x + v_x +v_x), y + v_y + character_height, (z + v_z + v_z), 0.f, 1.f, 0.f);
		}
		break;
	case 2://3인칭
		if (!right_button)
		{
			gluLookAt(x + camera_x, y + camera_y + (character_height * 2), z + camera_z, x + v_x, y + v_y + (character_height * 2), z + v_z, 0, 0.f, 1.f);
		}
		else
		{
			gluLookAt(x, y + 50, z, x + v_x, y + v_y + character_height, z + v_z, 0.f, 1.f, 0.f);
		}
		
		break;
	}
}
void Camera::CalculateView(int x, int y)
{
	//glm::mat4 view_mat;
	//view_mat = glm::lookAt(glm::vec3(x, 0.0, y), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
	if (player_view == 1 || player_view == 2)
	{
		glutSetCursor(GLUT_CURSOR_NONE);//커서 안보이게
		glutWarpPointer(WindowWidth / 2, WindowHeight / 2);//1인칭나 3인칭일떄는 중앙에 커서 고정
		c_x_angle = c_x_angle + (cen_x / mouse_sens);
		c_y_angle = c_y_angle + (cen_y / mouse_sens);
		v_z = 10000 * cos(c_x_angle* DEG2RAD) * sin(c_y_angle* DEG2RAD);
		v_x = 10000 * sin(c_x_angle* DEG2RAD) * sin(c_y_angle* DEG2RAD);
		v_y = 10000 * cos(c_y_angle* DEG2RAD);
		camera_z = -camera_distance * cos((c_x_angle + 5)*  DEG2RAD) * sin(c_y_angle* DEG2RAD);
		camera_x = -camera_distance * sin((c_x_angle + 5)*  DEG2RAD) * sin(c_y_angle* DEG2RAD);
		camera_y = -camera_distance * cos((c_y_angle - 5)*  DEG2RAD);	
		switch (player_view)
		{
		case 1:// 1인칭
			if (c_x_angle <= -360.f || c_x_angle >= 360.f)
			{
				c_x_angle = 0.f;
			}
			if (c_y_angle <= -179.f)
			{
				c_y_angle = -179.f;
			}
			else if (c_y_angle > -1.f)
			{
				c_y_angle = -1.f;
			}
			break;
		case 2://2ㄴㄴ3인칭
			if (c_x_angle <= -360.f || c_x_angle >= 360.f)
			{
				c_x_angle = 0.f;
			}
			if (c_y_angle <= -179.f)
			{
				c_y_angle = -179.f;
			}
			else if (c_y_angle >= -159.f) // -155이상부턴 날아다님 축이 뒤바뀌더라ㅏㅏㅏㅏ
			{
				c_y_angle = -160.f;
			}
			break;
		}
	}
}