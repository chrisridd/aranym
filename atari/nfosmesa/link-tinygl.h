/*
 * -- DO NOT EDIT --
 * Generated by dyngl.pl from ./tools/glfuncs.h
 */

#undef NUM_TINYGL_PROCS

GL_PROC(void, voidf, "information", tinyglinformation, "void information(void)", (NOTHING), ())
GL_PROC(void, voidf, "glBegin", glBegin, "void glBegin(GLenum mode)", (GLenum mode), (mode))
GL_PROC(void, voidf, "glClear", glClear, "void glClear(GLbitfield mask)", (GLbitfield mask), (mask))
GL_PROC(void, voidf, "glClearColor", glClearColor, "void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)", (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha), (red, green, blue, alpha))
GL_PROC(void, voidf, "glColor3f", glColor3f, "void glColor3f(GLfloat red, GLfloat green, GLfloat blue)", (GLfloat red, GLfloat green, GLfloat blue), (red, green, blue))
GL_PROC(void, voidf, "glDisable", glDisable, "void glDisable(GLenum cap)", (GLenum cap), (cap))
GL_PROC(void, voidf, "glEnable", glEnable, "void glEnable(GLenum cap)", (GLenum cap), (cap))
GL_PROC(void, voidf, "glEnd", glEnd, "void glEnd(void)", (NOTHING), ())
GL_PROC(void, voidf, "glLightfv", glLightfv, "void glLightfv(GLenum light, GLenum pname, const GLfloat *params)", (GLenum light, GLenum pname, const GLfloat *params), (light, pname, params))
GL_PROC(void, voidf, "glLoadIdentity", glLoadIdentity, "void glLoadIdentity(void)", (NOTHING), ())
GL_PROC(void, voidf, "glMaterialfv", glMaterialfv, "void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params)", (GLenum face, GLenum pname, const GLfloat *params), (face, pname, params))
GL_PROC(void, voidf, "glMatrixMode", glMatrixMode, "void glMatrixMode(GLenum mode)", (GLenum mode), (mode))
GL_PROC(void, voidf, "glOrtho", glOrthof, "void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near_val, GLfloat far_val)", (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near_val, GLfloat far_val), (left, right, bottom, top, near_val, far_val))
GL_PROC(void, voidf, "glPopMatrix", glPopMatrix, "void glPopMatrix(void)", (NOTHING), ())
GL_PROC(void, voidf, "glPushMatrix", glPushMatrix, "void glPushMatrix(void)", (NOTHING), ())
GL_PROC(void, voidf, "glRotatef", glRotatef, "void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)", (GLfloat angle, GLfloat x, GLfloat y, GLfloat z), (angle, x, y, z))
GL_PROC(void, voidf, "glTexEnvi", glTexEnvi, "void glTexEnvi(GLenum target, GLenum pname, GLint param)", (GLenum target, GLenum pname, GLint param), (target, pname, param))
GL_PROC(void, voidf, "glTexParameteri", glTexParameteri, "void glTexParameteri(GLenum target, GLenum pname, GLint param)", (GLenum target, GLenum pname, GLint param), (target, pname, param))
GL_PROC(void, voidf, "glTranslatef", glTranslatef, "void glTranslatef(GLfloat x, GLfloat y, GLfloat z)", (GLfloat x, GLfloat y, GLfloat z), (x, y, z))
GL_PROC(void, voidf, "glVertex2f", glVertex2f, "void glVertex2f(GLfloat x, GLfloat y)", (GLfloat x, GLfloat y), (x, y))
GL_PROC(void, voidf, "glVertex3f", glVertex3f, "void glVertex3f(GLfloat x, GLfloat y, GLfloat z)", (GLfloat x, GLfloat y, GLfloat z), (x, y, z))
GL_PROC(void *, return , "OSMesaCreateLDG", OSMesaCreateLDG, "void * OSMesaCreateLDG(GLenum format, GLenum type, GLint width, GLint height)", (GLenum format, GLenum type, GLint width, GLint height), (format, type, width, height))
GL_PROC(void, voidf, "OSMesaDestroyLDG", OSMesaDestroyLDG, "void OSMesaDestroyLDG(void)", (NOTHING), ())
GL_PROC(void, voidf, "glArrayElement", glArrayElement, "void glArrayElement(GLint i)", (GLint i), (i))
GL_PROC(void, voidf, "glBindTexture", glBindTexture, "void glBindTexture(GLenum target, GLuint texture)", (GLenum target, GLuint texture), (target, texture))
GL_PROC(void, voidf, "glCallList", glCallList, "void glCallList(GLuint list)", (GLuint list), (list))
GL_PROC(void, voidf, "glClearDepth", glClearDepthf, "void glClearDepthf(GLfloat d)", (GLfloat d), (d))
GL_PROC(void, voidf, "glColor4f", glColor4f, "void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)", (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), (red, green, blue, alpha))
GL_PROC(void, voidf, "glColor3fv", glColor3fv, "void glColor3fv(const GLfloat *v)", (const GLfloat *v), (v))
GL_PROC(void, voidf, "glColor4fv", glColor4fv, "void glColor4fv(const GLfloat *v)", (const GLfloat *v), (v))
GL_PROC(void, voidf, "glColorMaterial", glColorMaterial, "void glColorMaterial(GLenum face, GLenum mode)", (GLenum face, GLenum mode), (face, mode))
GL_PROC(void, voidf, "glColorPointer", glColorPointer, "void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)", (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), (size, type, stride, pointer))
GL_PROC(void, voidf, "glCullFace", glCullFace, "void glCullFace(GLenum mode)", (GLenum mode), (mode))
GL_PROC(void, voidf, "glDeleteTextures", glDeleteTextures, "void glDeleteTextures(GLsizei n, const GLuint *textures)", (GLsizei n, const GLuint *textures), (n, textures))
GL_PROC(void, voidf, "glDisableClientState", glDisableClientState, "void glDisableClientState(GLenum cap)", (GLenum cap), (cap))
GL_PROC(void, voidf, "glEnableClientState", glEnableClientState, "void glEnableClientState(GLenum cap)", (GLenum cap), (cap))
GL_PROC(void, voidf, "glEndList", glEndList, "void glEndList(void)", (NOTHING), ())
GL_PROC(void, voidf, "glEdgeFlag", glEdgeFlag, "void glEdgeFlag(GLboolean32 flag)", (GLboolean32 flag), (flag))
GL_PROC(void, voidf, "glFlush", glFlush, "void glFlush(void)", (NOTHING), ())
GL_PROC(void, voidf, "glFrontFace", glFrontFace, "void glFrontFace(GLenum mode)", (GLenum mode), (mode))
GL_PROC(void, voidf, "glFrustum", glFrustumf, "void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near_val, GLfloat far_val)", (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near_val, GLfloat far_val), (left, right, bottom, top, near_val, far_val))
GL_PROC(GLuint, return , "glGenLists", glGenLists, "GLuint glGenLists(GLsizei range)", (GLsizei range), (range))
GL_PROC(void, voidf, "glGenTextures", glGenTextures, "void glGenTextures(GLsizei n, GLuint *textures)", (GLsizei n, GLuint *textures), (n, textures))
GL_PROC(void, voidf, "glGetFloatv", glGetFloatv, "void glGetFloatv(GLenum pname, GLfloat *params)", (GLenum pname, GLfloat *params), (pname, params))
GL_PROC(void, voidf, "glGetIntegerv", glGetIntegerv, "void glGetIntegerv(GLenum pname, GLint *params)", (GLenum pname, GLint *params), (pname, params))
GL_PROC(void, voidf, "glHint", glHint, "void glHint(GLenum target, GLenum mode)", (GLenum target, GLenum mode), (target, mode))
GL_PROC(void, voidf, "glInitNames", glInitNames, "void glInitNames(void)", (NOTHING), ())
GL_PROC(GLboolean, return , "glIsList", glIsList, "GLboolean glIsList(GLuint list)", (GLuint list), (list))
GL_PROC(void, voidf, "glLightf", glLightf, "void glLightf(GLenum light, GLenum pname, GLfloat param)", (GLenum light, GLenum pname, GLfloat param), (light, pname, param))
GL_PROC(void, voidf, "glLightModeli", glLightModeli, "void glLightModeli(GLenum pname, GLint param)", (GLenum pname, GLint param), (pname, param))
GL_PROC(void, voidf, "glLightModelfv", glLightModelfv, "void glLightModelfv(GLenum pname, const GLfloat *params)", (GLenum pname, const GLfloat *params), (pname, params))
GL_PROC(void, voidf, "glLoadMatrixf", glLoadMatrixf, "void glLoadMatrixf(const GLfloat *m)", (const GLfloat *m), (m))
GL_PROC(void, voidf, "glLoadName", glLoadName, "void glLoadName(GLuint name)", (GLuint name), (name))
GL_PROC(void, voidf, "glMaterialf", glMaterialf, "void glMaterialf(GLenum face, GLenum pname, GLfloat param)", (GLenum face, GLenum pname, GLfloat param), (face, pname, param))
GL_PROC(void, voidf, "glMultMatrixf", glMultMatrixf, "void glMultMatrixf(const GLfloat *m)", (const GLfloat *m), (m))
GL_PROC(void, voidf, "glNewList", glNewList, "void glNewList(GLuint list, GLenum mode)", (GLuint list, GLenum mode), (list, mode))
GL_PROC(void, voidf, "glNormal3f", glNormal3f, "void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz)", (GLfloat nx, GLfloat ny, GLfloat nz), (nx, ny, nz))
GL_PROC(void, voidf, "glNormal3fv", glNormal3fv, "void glNormal3fv(const GLfloat *v)", (const GLfloat *v), (v))
GL_PROC(void, voidf, "glNormalPointer", glNormalPointer, "void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *ptr)", (GLenum type, GLsizei stride, const GLvoid *ptr), (type, stride, ptr))
GL_PROC(void, voidf, "glPixelStorei", glPixelStorei, "void glPixelStorei(GLenum pname, GLint param)", (GLenum pname, GLint param), (pname, param))
GL_PROC(void, voidf, "glPolygonMode", glPolygonMode, "void glPolygonMode(GLenum face, GLenum mode)", (GLenum face, GLenum mode), (face, mode))
GL_PROC(void, voidf, "glPolygonOffset", glPolygonOffset, "void glPolygonOffset(GLfloat factor, GLfloat units)", (GLfloat factor, GLfloat units), (factor, units))
GL_PROC(void, voidf, "glPopName", glPopName, "void glPopName(void)", (NOTHING), ())
GL_PROC(void, voidf, "glPushName", glPushName, "void glPushName(GLuint name)", (GLuint name), (name))
GL_PROC(GLint, return , "glRenderMode", glRenderMode, "GLint glRenderMode(GLenum mode)", (GLenum mode), (mode))
GL_PROC(void, voidf, "glSelectBuffer", glSelectBuffer, "void glSelectBuffer(GLsizei size, GLuint *buffer)", (GLsizei size, GLuint *buffer), (size, buffer))
GL_PROC(void, voidf, "glScalef", glScalef, "void glScalef(GLfloat x, GLfloat y, GLfloat z)", (GLfloat x, GLfloat y, GLfloat z), (x, y, z))
GL_PROC(void, voidf, "glShadeModel", glShadeModel, "void glShadeModel(GLenum mode)", (GLenum mode), (mode))
GL_PROC(void, voidf, "glTexCoord2f", glTexCoord2f, "void glTexCoord2f(GLfloat s, GLfloat t)", (GLfloat s, GLfloat t), (s, t))
GL_PROC(void, voidf, "glTexCoord4f", glTexCoord4f, "void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)", (GLfloat s, GLfloat t, GLfloat r, GLfloat q), (s, t, r, q))
GL_PROC(void, voidf, "glTexCoord2fv", glTexCoord2fv, "void glTexCoord2fv(const GLfloat *v)", (const GLfloat *v), (v))
GL_PROC(void, voidf, "glTexCoordPointer", glTexCoordPointer, "void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)", (GLint size, GLenum type, GLsizei stride, const GLvoid *ptr), (size, type, stride, ptr))
GL_PROC(void, voidf, "glTexImage2D", glTexImage2D, "void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)", (GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels), (target, level, internalFormat, width, height, border, format, type, pixels))
GL_PROC(void, voidf, "glVertex4f", glVertex4f, "void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)", (GLfloat x, GLfloat y, GLfloat z, GLfloat w), (x, y, z, w))
GL_PROC(void, voidf, "glVertex3fv", glVertex3fv, "void glVertex3fv(const GLfloat *v)", (const GLfloat *v), (v))
GL_PROC(void, voidf, "glVertexPointer", glVertexPointer, "void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)", (GLint size, GLenum type, GLsizei stride, const GLvoid *ptr), (size, type, stride, ptr))
GL_PROC(void, voidf, "glViewport", glViewport, "void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)", (GLint x, GLint y, GLsizei width, GLsizei height), (x, y, width, height))
GL_PROC(void, voidf, "swapbuffer", tinyglswapbuffer, "void swapbuffer(void *buffer)", (void *buffer), (buffer))
GL_PROC(GLsizei, return , "max_width", max_width, "GLsizei max_width(void)", (NOTHING), ())
GL_PROC(GLsizei, return , "max_height", max_height, "GLsizei max_height(void)", (NOTHING), ())
GL_PROC(void, voidf, "glDeleteLists", glDeleteLists, "void glDeleteLists(GLuint list, GLsizei range)", (GLuint list, GLsizei range), (list, range))
GL_PROC(void, voidf, "gluLookAt", gluLookAtf, "void gluLookAtf(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat upX, GLfloat upY, GLfloat upZ)", (GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat upX, GLfloat upY, GLfloat upZ), (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ))
GL_PROC(void, voidf, "exception_error", tinyglexception_error, "void exception_error(void (CALLBACK *exception)(GLenum param) )", (void (CALLBACK *exception)(GLenum param) ), (exception))

#undef GL_PROC
#undef GL_PROC64
#define NUM_TINYGL_PROCS 83

/* Functions generated: 83 */

