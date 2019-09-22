#pragma once
#include "stdafx.h"

class Camera {
	int cen_x, cen_y;	//마우스용
	float c_x_angle, c_y_angle;
	float v_x, v_y, v_z;
	float camera_x, camera_y, camera_z;
	float camera_distance;
	float center_x, center_y;
	int mouse_sens; // 마우스 감도
	/*Vector3D v_right;
	Vector3D v_up;
	Vector3D v_look;
	Vector3D v_position;*/

	//glm::vec3 c_target;
	//glm::vec3 c_direction;
	//glm::vec3 up; // 위쪽벡터
	//glm::vec3 c_up;
	//glm::vec3 c_right;
	//glm::vec3 c_position;

public:
	Camera();
	~Camera();

	void InitCamera();
	void UpdateView(bool right_button,float x, float y, float z, float character_height);
	void CalculateView(int x, int y);
	void ChangeMouseSens(bool updown);

	float GetCameraXAngle();
	float GetCameraYAngle();
	float GetViewX();
	float GetViewY();
	float GetViewZ();
	float GetCameraX();
	float GetCameraY();
	float GetCameraZ();
	float GetCameraDistance();
	int GetCenX();
	int GetCenY();

	void SetCameraXAngle(float angle);
	void SetCameraYAngle(float angle);
	void SetViewX(float x);
	void SetViewY(float y);
	void SetViewZ(float z);
	void SetCameraX(float x);
	void SetCameraY(float y);
	void SetCameraZ(float z);
	void SetCameraDistance(float dis);
	void SetCenX(int x);
	void SetCenY(int y);

	//void ForwardOrBackward(GLfloat);//카메라 앞 뒤 움직임
	//void LeftOrRight(GLfloat);//좌우 움직임
	//void UpOrDown(GLfloat);//위아래 움직임
	//void Pitch(GLfloat);//카메라 v_right 축으로 회전
	//void Yaw(GLfloat);//카메라 v_up 축으로 회전
	//void Roll(GLfloat);//카메라 vLook을 축으로 회적
	//void GetViewMatrix(Matirx*);
};