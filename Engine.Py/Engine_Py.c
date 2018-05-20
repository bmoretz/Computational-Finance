#include <Python.h>

/*
 * Implements Random Walk Function
 */
PyDoc_STRVAR(EnginePy_RandonWalk_doc, "RandomWalk(obj, size, obj, start, obj, step )\
\
Random Walk Function");

PyObject* EnginePy_RandomWalk( PyObject *self, PyObject *args, PyObject *kwargs )
{
	/* Shared references that do not need Py_DECREF before returning. */
	PyObject *obj = NULL;
	int size = 0;
	double start = 0.0;
	double step = 0.0;

	/* Parse positional and keyword arguments */
	static char *keywords[] =
	{
		"obj", "size", NULL,
		"obj", "start", NULL,
		"obj", "step", NULL
	};

	if( !PyArg_ParseTupleAndKeywords( args, kwargs, "Oi", keywords, &obj, &size, &start, &step ) )
	{
		return NULL;
	}

	/* Function implementation starts here */


	Py_RETURN_NONE;
}

/*
 * List of functions to add to Engine_Py in exec_Engine_Py().
 */
static PyMethodDef Engine_Py_functions[] = {
	{ "example", ( PyCFunction ) EnginePy_RandomWalk, METH_VARARGS | METH_KEYWORDS, EnginePy_RandonWalk_doc },
	{ NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize Engine_Py. May be called multiple times, so avoid
 * using static state.
 */
int exec_Engine_Py( PyObject *module )
{
	PyModule_AddFunctions( module, Engine_Py_functions );

	PyModule_AddStringConstant( module, "__author__", "bmoretz" );
	PyModule_AddStringConstant( module, "__version__", "1.0.0" );
	PyModule_AddIntConstant( module, "year", 2018 );

	return 0; /* success */
}

/*
 * Documentation for Engine_Py.
 */
PyDoc_STRVAR(Engine_Py_doc, "The EnginePy module");

static PyModuleDef_Slot Engine_Py_slots[] = {
	{ Py_mod_exec, exec_Engine_Py },
	{ 0, NULL }
};

static PyModuleDef Engine_Py_def = {
	PyModuleDef_HEAD_INIT,
	"EnginePy",
	Engine_Py_doc,
	0, /* m_size */
	NULL, /* m_methods */
	Engine_Py_slots,
	NULL, /* m_traverse */
	NULL, /* m_clear */
	NULL, /* m_free */
};

PyMODINIT_FUNC PyInit_Engine_Py()
{
	return PyModuleDef_Init( &Engine_Py_def );
}
