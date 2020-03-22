#include<GL/glut.h>

void display();
void reshape(int ,int);
void timer(int);
void init();


//Global position vars


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //GLUT_DOUBLE helps in taking away distortions in low performance computers
//GLUT_DOUBLE uses two buffers. One for drawing another for displaying.
//in display() function instead of using: glFlush();, we use glutSwapBuffers();
//Images will be displayed slowly than glFlush() but it wont be distorted.

    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Trial Window");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // Call timer function per 0 milliseconds. Doesnt make sense i Know.
    //Go to the timer function it will then.

    init();

    glutMainLoop();
}

void init(){
    glClearColor(0,0,0,1);
}

float square_xpos = -10.0;
//float square_ypos = 0.0;
int state = 1;


void display(){
    glClear(GL_COLOR_BUFFER_BIT); //Clear whatever is in the
    glLoadIdentity(); //Reset 'internal variables'

    // glPointSize(10);

    // A trapezium shaped grass(green) ground
    glColor3d(0,1,0);   //Green Color
    glBegin(GL_QUADS);
        glVertex2d(-7, 0);
        glVertex2d(-9, -9);
        glVertex2d(9, -9);
        glVertex2d(7, 0);
    glEnd();

    //A red square moving back and forth
    glColor3d(1,0,0);   //Red
    glBegin(GL_QUADS);
        glVertex2f(square_xpos, 1.0);
        glVertex2f(square_xpos ,-1.0);
        glVertex2f(square_xpos+2.0, -1.0);
        glVertex2f(square_xpos+2.0, 1.0);
    glEnd();



    glutSwapBuffers();
}

void reshape(int width, int heigth){
    glViewport(0 , 0, (GLsizei)width, (GLsizei)heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int){
    glutPostRedisplay();
    //Display the display() function again and again. because glutDisplayFunc() calls display()
    glutTimerFunc(1000/60, timer, 0); //For 60fps => 1000ms/ 60frames = 16.67 fps = 17fps

    //Logic for animation:
    switch(state)
    {
    case 1:
            if(square_xpos < 5.0)
                square_xpos += 0.2;
            else
                state = -1;
        break;
    case -1:
            if(square_xpos >(-7.0))
                square_xpos -= 0.2;
            else
                state = 1;
            break;
    }
}
