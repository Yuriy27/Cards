

//#include <GL/glut.h>

class Card
{
	public:
		float x;
		float y;
		float z;
		float xLength;
		float yLength;
		float zLength;
		
		float xRot;
		float yRot;
		float zRot;
		
		GLuint texture[1];
		
		void loadTextures()
		{
			AUX_RGBImageRec *texture1;
        	texture1 = auxDIBImageLoad("sample.bmp");
        	
        	glGenTextures(1, &texture[0]);
	        glBindTexture(GL_TEXTURE_2D, texture[0]);
	        
	        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
		}
		
		Card()
		{
			x = y = z = 0;
			xLength = yLength = zLength = 1;
			loadTextures();
		}
		
		Card(float x, float y, float z, float xLength, float yLength, float zLength, float xRot, float yRot, float zRot)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->xLength = xLength;
			this->yLength = yLength;
			this->zLength = zLength;
			this->xRot = xRot;
			this->yRot = yRot;
			this->zRot = zRot;
			
			loadTextures();
		}
		
		void draw()
		{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
 

  glRotatef(xRot, 1.0, 0.0, 0.0 );
  glRotatef(yRot, 0.0, 1.0, 0.0 );
  glRotatef(zRot, 0.0, 0.0, 1.0 );
  
  glBindTexture(GL_TEXTURE_2D, texture[0]);
   
  glBegin(GL_QUADS); 

 
  //glColor3f( 1.0, 0.0, 0.0 );     
  glTexCoord2f(0.0f, 0.0f); glVertex3f(  x+xLength, y-yLength, z-zLength );      // P1 is red
  //glColor3f( 0.0, 1.0, 0.0 );     
  glTexCoord2f(0.0f, 1.0f); glVertex3f(  x+xLength,  y+yLength, z-zLength );      // P2 is green
  //glColor3f( 0.0, 0.0, 1.0 );     
  glTexCoord2f(1.0f, 1.0f); glVertex3f( x-xLength,  y+yLength, z-zLength );      // P3 is blue
  //glColor3f( 1.0, 0.0, 1.0 );     
  glTexCoord2f(1.0f, 0.0f); glVertex3f( x-xLength, y-yLength, z-zLength );      // P4 is purple
 

 
  // White side - BACK

  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  x+xLength, y-yLength, z+zLength );
  glVertex3f(  x+xLength,  y+yLength, z+zLength );
  glVertex3f( x-xLength,  y+yLength, z+zLength );
  glVertex3f( x-xLength, y-yLength, z+zLength );

 
  // Purple side - RIGHT

  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( x+xLength, y-yLength, z-zLength );
  glVertex3f( x+xLength,  y+yLength, z-zLength );
  glVertex3f( x+xLength,  y+yLength,  z+zLength );
  glVertex3f( x+xLength, y-yLength,  z+zLength );

 
  // Green side - LEFT

  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( x-xLength, y-yLength,  z+zLength );
  glVertex3f( x-xLength,  y+yLength,  z+zLength );
  glVertex3f( x-xLength,  y+yLength, z-zLength );
  glVertex3f( x-xLength, y-yLength, z-zLength );

 
  // Blue side - TOP

  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f( x+xLength,  y+yLength,  z+zLength );
  glVertex3f( x+xLength,  y+yLength, z-zLength );
  glVertex3f( x-xLength,  y+yLength, z-zLength );
  glVertex3f( x-xLength,  y+yLength,  z+zLength );

 
  // Red side - BOTTOM

  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f( x+xLength, y-yLength, z-zLength );
  glVertex3f( x+xLength, y-yLength,  z+zLength );
  glVertex3f( x-xLength, y-yLength,  z+zLength );
  glVertex3f( x-xLength, y-yLength, z-zLength );

  glEnd();
  
  xRot += 3;
  yRot += 3;
  zRot += 3;
  
  glFlush();
  glutSwapBuffers();
  
  
		}
		
		void comparativeCoords(float x, float y, float z)
		{
			this->x += x;
			this->y += y;
			this->z += z;
		}
		
		void absoluteCoords(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
};
