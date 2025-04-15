#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
using namespace std;

int main() {
    MySQLConexion conn("localhost", "usuario", "contraseña", "nombre_base_datos");
    if (!conn.conectar()) {
        cerr << "No se pudo conectar." << endl;
        return 1;
    }

    vector<string> columnas = {"id", "nombre", "hora_entrada", "hora_salida"};
    EloquentORM empleados(conn, "empleados", columnas);

    auto lista = empleados.getAll();
    for (auto &reg : lista) {
        cout << "ID: " << reg["id"] << ", Nombre: " << reg["nombre"] << endl;
    }

    return 0;
}