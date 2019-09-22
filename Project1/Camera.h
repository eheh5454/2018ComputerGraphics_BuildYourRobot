#pragma once
#include "stdafx.h"

class Camera {
	int cen_x, cen_y;	//���콺��
	float c_x_angle, c_y_angle;
	float v_x, v_y, v_z;
	float camera_x, camera_y, camera_z;
	float camera_distance;
	float center_x, center_y;
	int mouse_sens; // ���콺 ����
	/*Vector3D v_right;
	Vector3D v_up;
	Vector3D v_look;
	Vector3D v_position;*/

	//glm::vec3 c_target;
	//glm::vec3 c_direction;
	//glm::vec3 up; // ���ʺ���
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

	//void ForwardOrBackward(GLfloat);//ī�޶� �� �� ������
	//void LeftOrRight(GLfloat);//�¿� ������
	//void UpOrDown(GLfloat);//���Ʒ� ������
	//void Pitch(GLfloat);//ī�޶� v_right ������ ȸ��
	//void Yaw(GLfloat);//ī�޶� v_up ������ ȸ��
	//void Roll(GLfloat);//ī�޶� vLook�� ������ ȸ��
	//void GetViewMatrix(Matirx*);
};