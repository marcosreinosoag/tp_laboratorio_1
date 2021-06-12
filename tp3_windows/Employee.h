#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee* this);
int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this, int* flagError);
int isValidId(char* id);
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* flagError);
int isValidHorasTrabajadas(char* horasTrabajadas);
int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this, int* flagError);
int isValidSueldo(char* sueldo);
int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this, int* flagError);
int isValidNombre(char* tipo);


#endif // employee_H_INCLUDED
