// StringGraph.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <cstdbool>
#include <stdbool.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <tuple>

using namespace std;

//Funcion que lee una palabra y devuelva todo
//Antes de que encuentre el caracter ":"
string process(string const& s) {
    string::size_type pos = s.find(':');
    if (pos != std::string::npos)
    {
        return s.substr(0, pos);
    }
    else
    {
        return s;
    }
}

//Funcion que devuelve la tercera y cuarta palabra
//De un string despues de removerle el texto antes del primer ":"
//En el contexto de este programa, devolvera la Ip inicial y la Ip final
tuple<string, string> returnThirdAndFourthWord(string str)
{
    // word variable to store word
    string word;
    int contador = 0;
    string terceraP, cuartaP;

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word) {
        if (contador == 3) {
            //cout << word << " ";
            terceraP = process(word);
        }
        if (contador == 4) {
            //cout << word << endl;
            cuartaP = process(word);
        }
        contador++;
    }
    return { terceraP, cuartaP };
}

//Funcion que leera dos numeros separados por un espacio
//Y los devolvera como Int
tuple<int, int> ReturnFirstAndSecondNumber(string str) {
    string word;
    int contador = 0;
    int primeraP, segundaP;
    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word) {
        if (contador == 0) {
            //cout << word << " ";
            primeraP = stoi(word);
        }
        if (contador == 1) {
            //cout << word << endl;
            segundaP = stoi(word);
        }
        contador++;
    }
    return { primeraP, segundaP };
}

//Funcion que regresa la primera palabra de cada linea
string ReturnFirstWord(string str) {
    string word;
    int contador = 0;
    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word) {
        if (contador == 0) {
            //cout << word << endl;
            return word;
        }
        contador++;
    }
    return word;
}

//Implementacion de Grafo
//Con lista de Adyacencia
class Graph
{
public:
    map<string, list<string>> adj;

    // function to add an edge to graph
    void addEdge(string v, string w);

};

void Graph::addEdge(string v, string w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// Driver code
int main()
{
    // Creacion del grafo
    Graph g;

    int firstNumber, secondNumber;
    int i = 0, j;
    string ThirdWord, FourthWord, Node, Edge;

    //Cargamos Nombre de archivo
    string filename;
    filename = "bitacoraACT4_3.txt";

    string Linea;

    //Leer solo la primera Linea (Nodes,Edges)
    ifstream infile(filename);
    getline(infile, Linea);
    istringstream iss(Linea);
    tie(firstNumber, secondNumber) = ReturnFirstAndSecondNumber(Linea);

    //Leemos todos los Nodes y los anadimos a Graph
    //Solo se avanza el archivo hasta la segunda parte
    while (std::getline(infile, Linea))
    {
        //Primera parte, Ips Solas.
        istringstream iss(Linea);
        Node = ReturnFirstWord(Linea);
        //Anadir el Node a Graph
        //Graph.[i] = Node;
        if (i < firstNumber - 1) {
            i++;
        }
        else {
            break;
        }

    }
    i = 0;
    //Leemos todos Edges y los anadimos a Graph
    while (std::getline(infile, Linea)) {
        istringstream iss(Linea);
        tie(ThirdWord, FourthWord) = returnThirdAndFourthWord(Linea);
        //Anadimos el Edge a Graph
        if (i < secondNumber) {
            g.addEdge(ThirdWord, FourthWord);
            i++;
        }
        else {
            break;
        }
    }
    
    cout << "Tamano actual ";
    cout << g.adj.size() << endl;

    cout << "Iterar a traves de los componentes de la lista " << endl;

    //Iterador g.adj
    //Devuelve todos los nodos
    map<string, list<string>>::iterator o;
    for (o = g.adj.begin(); o != g.adj.end(); ++o) {

        cout << o->first << " size: " << o->second.size() << endl;
    }


    return 0;
}

