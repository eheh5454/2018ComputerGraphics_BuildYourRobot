#include "stdafx.h"
#include "Body.h"

Body::Body(float size) : size{ size }
{

}
Body::~Body()
{

}
float Body::GetSize()
{
	return size;
}
void Body::Draw(int num)
{
	switch (num)
	{
	case 1:
		glPushMatrix();//∏ˆ≈Î
		{
			if (now_game_state == select_model)
				glTranslatef(0, -size * 2, 0);
			glPushMatrix();
			{
				glTranslatef(0, size * 2, 0);//∏ˆ≈Îπÿ
				glScalef(2, 1, 1);
				glLineWidth(5.f);
				glColor4f(0.f, 0.f, 1.f, 1.f);
				glutWireCube(size);
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glutSolidCube(size);


				glTranslatef(0, size, 0);//∏ˆ≈Î¿ß
				glScalef(1.5, 2, 1);
				glPushMatrix();
				{
					glTranslatef(0, 0, -size);
					glColor4f(0.f, 0.f, 1.f, 1.f);
					glutSolidCylinder(size / 2, size, 8, 1);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutWireCylinder(size / 2, size, 8, 1);
					glPushMatrix();//ƒ‡«Õ
					{
						glColor4f(0, 0.3, 0.3, 1);
						glTranslatef(0, size / 6, -size / 4.5);
						glRotatef(180, 1, 0, 0);
						glutSolidCone(size / 2.5, size / 1.5, 4, 1);
						glColor4f(1, 1, 1, 1);
						glutWireCone(size / 2.5, size / 1.5, 4, 1);
					}
					glPopMatrix();
				}
				glPopMatrix();

				glLineWidth(3.f);
				glPushMatrix();//µﬁ∫Œ∫–
				{
					glTranslatef(1 / size, size / 4, size / 2);

					glPushMatrix();//∞°Ω∫∫–√‚
					{
						glColor4f(0, 0, 0, 1);
						glTranslatef(size / 4, -size / 2, size / 2);
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(size / 6, size / 6, size, size);

					}
					glPopMatrix();
					glPushMatrix();
					{
						glColor4f(0, 0, 0, 1);
						glTranslatef(-size / 4, -size / 2, size / 2);
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(size / 6, size / 6, size, size);

					}
					glPopMatrix();
					glPushMatrix();//∞°Ω∫≈Î
					{
						glColor4f(0, 0.3, 0.3, 1);
						glScalef(0.8, 1, 1);
						glutSolidCube(size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//≥Ø∞≥
			{
				glPushMatrix();
				{
					glTranslatef(0, size * 9 / 2 + (size / 2), 0);
					glPushMatrix();
					{
						glPushMatrix();
						{
							glRotatef(15, 0, 0, 1);
							glTranslatef(size, size, size * 2);
							glRotatef(0, 0, 0, 1);
							glTranslatef(size / 2, 0, size / 2);
							glRotatef(0, 0, 0, 1);
							glRotatef(45, 1, 0, 0);
							glRotatef(size, 1, 0, 0);
							glPushMatrix();
							{
								glColor4f(1, 1, 1, 1);
								glutWireCone(size / 2, size * 5, 4, 1);
								glColor4f(0, 0, 1, 1);
								glutSolidCone(size / 2, size * 5, 4, 1);
							}
							glPopMatrix();
							//≥Ø∞≥πÿ
							glRotatef(-180, 1, 0, 0);
							glColor4f(1, 1, 1, 1);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(0, 0, 1, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();
						glPushMatrix();
						{
							glRotatef(-15, 0, 0, 1);
							glPushMatrix();
							{
								glTranslatef(-size, size, size * 2);
								glRotatef(0, 0, 0, 1);
								glTranslatef(-size / 2, 0, size / 2);
								glRotatef(0, 0, 0, 1);
								glRotatef(45, 1, 0, 0);
								glRotatef(size, 1, 0, 0);
								glPushMatrix();
								{
									glColor4f(1, 1, 1, 1);
									glutWireCone(size / 2, size * 5, 4, 1);
									glColor4f(0, 0, 1, 1);
									glutSolidCone(size / 2, size * 5, 4, 1);
								}
								glPopMatrix();
								//≥Ø∞≥πÿ
								glRotatef(-180, 1, 0, 0);
								glColor4f(1, 1, 1, 1);
								glutWireCone(size / 2, size * 3, 4, 1);
								glColor4f(0, 0, 1, 1);
								glutSolidCone(size / 2, size * 3, 4, 1);
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
				glPushMatrix();
				{
					glPushMatrix();
					{
						glTranslatef(0, size * 3, size * 2);
						glRotatef(0, 0, 0, 1);
						glTranslatef(size / 2, 0, size / 2);
						glRotatef(0, 0, 0, 1);
						glRotatef(45, 1, 0, 0);
						glRotatef(size, 1, 0, 0);
						glPushMatrix();					//≥Ø∞≥πÿ
						{
							glColor4f(1, 1, 1, 1);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(0, 0, 1, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();

						glRotatef(180, 1, 0, 0);
						glColor4f(1, 1, 1, 1);
						glutWireCone(size / 2, size * 3, 4, 1);
						glColor4f(0, 0, 1, 1);
						glutSolidCone(size / 2, size * 3, 4, 1);
					}
					glPopMatrix();
					glPushMatrix();
					{
						glTranslatef(0, size * 3, size * 2);
						glRotatef(0, 0, 0, 1);
						glTranslatef(-size / 2, 0, size / 2);
						glRotatef(0, 0, 0, 1);
						glRotatef(45, 1, 0, 0);
						glRotatef(size, 1, 0, 0);
						glPushMatrix();					//≥Ø∞≥πÿ
						{
							glColor4f(1, 1, 1, 1);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(0, 0, 1, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();

						glRotatef(-180, 1, 0, 0);
						glColor4f(1, 1, 1, 1);
						glutWireCone(size / 2, size * 3, 4, 1);
						glColor4f(0, 0, 1, 1);
						glutSolidCone(size / 2, size * 3, 4, 1);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();//∏ˆ≈Î
		{
			if (now_game_state == select_model)
				glTranslatef(0, -size * 2, 0);
			glPushMatrix();
			{
				glTranslatef(0, size * 2, 0);//∏ˆ≈Îπÿ
				glScalef(2, 1, 1);
				glLineWidth(5.f);
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glutWireCube(size);
				glColor4f(1.f, 0.f, 0.f, 1.f);
				glutSolidCube(size);

				glTranslatef(0, size, 0);//∏ˆ≈Î¿ß
				glScalef(1.5, 2, 1);
				glPushMatrix();
				{
					glTranslatef(0, 0, -size);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutSolidCylinder(size / 2, size, 8, 1);
					glColor4f(1.f, 0.f, 0.f, 1.f);
					glutWireCylinder(size / 2, size, 8, 1);
					glPushMatrix();//ƒ‡«Õ
					{
						glColor4f(1, 0, 0, 1);
						glTranslatef(0, size / 6, -size / 4.5);
						glRotatef(180, 1, 0, 0);
						glutSolidCone(size / 2.5, size / 1.5, 4, 1);
						glColor4f(1, 1, 1, 1);
						glutWireCone(size / 2.5, size / 1.5, 4, 1);
					}
					glPopMatrix();
				}
				glPopMatrix();

				glLineWidth(3.f);
				glPushMatrix();//µﬁ∫Œ∫–
				{
					glTranslatef(1 / size, size / 4, size / 2);

					glPushMatrix();//∞°Ω∫∫–√‚
					{
						glColor4f(0, 0, 0, 1);
						glTranslatef(size / 4, -size / 2, size / 2);
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(size / 6, size / 6, size, size);

					}
					glPopMatrix();
					glPushMatrix();
					{
						glColor4f(0, 0, 0, 1);
						glTranslatef(-size / 4, -size / 2, size / 2);
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(size / 6, size / 6, size, size);

					}
					glPopMatrix();
					glPushMatrix();//∞°Ω∫≈Î
					{
						glColor4f(1, 0, 0, 1);
						glScalef(0.8, 1, 1);
						glutSolidCube(size);
						glColor4f(1, 1, 1, 1);
						glutWireCube(size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//≥Ø∞≥
			{
				glPushMatrix();
				{
					glTranslatef(0, size * 9 / 2 + (size / 2), 0);
					glPushMatrix();
					{
						glPushMatrix();
						{
							glTranslatef(size, size, size * 2);
							glRotatef(0, 0, 0, 1);
							glTranslatef(size / 2, 0, size / 2);
							glRotatef(0, 0, 0, 1);
							glRotatef(45, 1, 0, 0);
							glRotatef(size, 1, 0, 0);
							glPushMatrix();
							{
								glColor4f(0, 0, 1, 1);
								glutWireCone(size / 2, size * 5, 4, 1);
								glColor4f(1, 0, 0, 1);
								glutSolidCone(size / 2, size * 5, 4, 1);
							}
							glPopMatrix();
							//≥Ø∞≥πÿ
							glRotatef(-180, 1, 0, 0);
							glColor4f(0, 0, 1, 1);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(1, 0, 0, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();
						glPushMatrix();
						{
							glPushMatrix();
							{
								glTranslatef(-size, size, size * 2);
								glRotatef(0, 0, 0, 1);
								glTranslatef(-size / 2, 0, size / 2);
								glRotatef(0, 0, 0, 1);
								glRotatef(45, 1, 0, 0);
								glRotatef(size, 1, 0, 0);
								glPushMatrix();
								{
									glColor4f(0, 0, 1, 1);
									glutWireCone(size / 2, size * 5, 4, 1);
									glColor4f(1, 0, 0, 1);
									glutSolidCone(size / 2, size * 5, 4, 1);
								}
								glPopMatrix();
								//≥Ø∞≥πÿ
								glRotatef(-180, 1, 0, 0);
								glColor4f(0, 0, 1, 1);
								glutWireCone(size / 2, size * 3, 4, 1);
								glColor4f(1, 0, 0, 1);
								glutSolidCone(size / 2, size * 3, 4, 1);
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();//∏ˆ≈Î
		{
			if (now_game_state == select_model)
				glTranslatef(0, -size * 2, 0);
			glPushMatrix();
			{
				glTranslatef(0, size * 2, 0);//∏ˆ≈Îπÿ
				glScalef(2, 1, 1);
				glLineWidth(5.f);
				glColor4f(0.5, 0.5, 0.5, 1.f);
				glutWireCube(size);
				glColor4f(0, 0.3, 0.3, 1);
				glutSolidCube(size);

				glTranslatef(0, size, 0);//∏ˆ≈Î¿ß
				glScalef(1.5, 2, 1);
				glPushMatrix();
				{
					glTranslatef(0, 0, -size);
					glColor4f(0, 0.3, 0.3, 1);
					glutSolidCylinder(size / 2, size, 8, 1);
					glColor4f(0.5, 0.5, 0.5, 1.f);
					glutWireCylinder(size / 2, size, 8, 1);
					glPushMatrix();//ƒ‡«Õ
					{
						glColor4f(0, 0.3, 0.3, 1);
						glTranslatef(0, size / 6, -size / 4.5);
						glRotatef(90, 1, 0, 0);
						glutSolidCone(size / 2.5, size / 1.5, 4, 1);
						glColor4f(0.5, 0.5, 0.5, 1.f);
						glutWireCone(size / 2.5, size / 1.5, 4, 1);
					}
					glPopMatrix();
				}
				glPopMatrix();

				glLineWidth(3.f);
				glPushMatrix();//µﬁ∫Œ∫–
				{
					glTranslatef(1 / size, size / 4, size / 2);

					glPushMatrix();//∞°Ω∫∫–√‚
					{
						glColor4f(0, 0, 0, 1);
						glTranslatef(size / 4, -size / 2, size / 2);
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(size / 6, size / 6, size, size);

					}
					glPopMatrix();
					glPushMatrix();
					{
						glColor4f(0, 0, 0, 1);
						glTranslatef(-size / 4, -size / 2, size / 2);
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(size / 6, size / 6, size, size);

					}
					glPopMatrix();
					glPushMatrix();//∞°Ω∫≈Î
					{
						glColor4f(0, 0.3, 0.3, 1);
						glScalef(0.8, 1, 1);
						glutSolidCube(size);
						glColor4f(0.5, 0.5, 0.5, 1.f);
						glutWireCube(size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//≥Ø∞≥
			{
				glPushMatrix();
				{
					glTranslatef(0, size * 9 / 2 + (size / 2), 0);
					glPushMatrix();
					{
						glPushMatrix();
						{
							glTranslatef(size, size, size * 2);
							glRotatef(0, 0, 0, 1);
							glTranslatef(size / 2, 0, size / 2);
							glRotatef(0, 0, 0, 1);
							glRotatef(90, 1, 0, 0);
							glRotatef(size, 1, 0, 0);
							glPushMatrix();
							{
								glColor4f(0.5, 0.5, 0.5, 1.f);
								glutWireCone(size / 2, size * 5, 4, 1);
								glColor4f(0, 0.3, 0.3, 1);
								glutSolidCone(size / 2, size * 5, 4, 1);
							}
							glPopMatrix();
							//≥Ø∞≥πÿ
							glRotatef(-180, 1, 0, 0);
							glColor4f(0.5, 0.5, 0.5, 1.f);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(0, 0.3, 0.3, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();
						glPushMatrix();
						{
							glTranslatef(-size, size, size * 2);
							glRotatef(0, 0, 0, 1);
							glTranslatef(-size / 2, 0, size / 2);
							glRotatef(0, 0, 0, 1);
							glRotatef(90, 1, 0, 0);
							glRotatef(size, 1, 0, 0);
							glPushMatrix();
							{
								glColor4f(0.5, 0.5, 0.5, 1.f);
								glutWireCone(size / 2, size * 5, 4, 1);
								glColor4f(0, 0.3, 0.3, 1);
								glutSolidCone(size / 2, size * 5, 4, 1);
							}
							glPopMatrix();
							//≥Ø∞≥πÿ
							glRotatef(-180, 1, 0, 0);
							glColor4f(0.5, 0.5, 0.5, 1.f);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(0, 0.3, 0.3, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();
						glPushMatrix();
						{
							glTranslatef(size, size, size * 2);
							glRotatef(0, 0, 0, 1);
							glTranslatef(size / 2, 0, size / 2);
							glRotatef(0, 0, 0, 1);
							glRotatef(45, 1, 0, 0);
							glRotatef(size, 1, 0, 0);
							glPushMatrix();
							{
								glColor4f(0.5, 0.5, 0.5, 1.f);
								glutWireCone(size / 2, size * 5, 4, 1);
								glColor4f(0, 0.3, 0.3, 1);
								glutSolidCone(size / 2, size * 5, 4, 1);
							}
							glPopMatrix();
							//≥Ø∞≥πÿ
							glRotatef(-180, 1, 0, 0);
							glColor4f(0.5, 0.5, 0.5, 1.f);
							glutWireCone(size / 2, size * 3, 4, 1);
							glColor4f(0, 0.3, 0.3, 1);
							glutSolidCone(size / 2, size * 3, 4, 1);
						}
						glPopMatrix();
						glPushMatrix();
						{
							glPushMatrix();
							{
								glTranslatef(-size, size, size * 2);
								glRotatef(0, 0, 0, 1);
								glTranslatef(-size / 2, 0, size / 2);
								glRotatef(0, 0, 0, 1);
								glRotatef(45, 1, 0, 0);
								glRotatef(size, 1, 0, 0);
								glPushMatrix();
								{
									glColor4f(0.5, 0.5, 0.5, 1.f);
									glutWireCone(size / 2, size * 5, 4, 1);
									glColor4f(0, 0.3, 0.3, 1);
									glutSolidCone(size / 2, size * 5, 4, 1);
								}
								glPopMatrix();
								//≥Ø∞≥πÿ
								glRotatef(-180, 1, 0, 0);
								glColor4f(0.5, 0.5, 0.5, 1.f);
								glutWireCone(size / 2, size * 3, 4, 1);
								glColor4f(0, 0.3, 0.3, 1);
								glutSolidCone(size / 2, size * 3, 4, 1);
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	}
	
}