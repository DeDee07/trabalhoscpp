#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <ctime>

using namespace std;

void limparEntrada() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pausa() {
	cout << "\nPressione Enter para continuar...";
	string tmp;
	getline(cin, tmp);
}

int lerOpcao() {
	int opc;
	cout << "\n===== MENU =====\n";
	cout << "1) Somar dois números\n";
	cout << "2) Inverter uma string\n";
	cout << "3) Mostrar data/hora atual\n";
	cout << "0) Sair\n";
	cout << "Escolha uma opção: ";
	if (!(cin >> opc)) {
		limparEntrada();
		return -1; // entrada inválida
	}
	limparEntrada();
	return opc;
}

void opcaoSomar() {
	double a, b;
	cout << "Digite o primeiro número: ";
	while (!(cin >> a)) {
		cout << "Entrada inválida. Digite um número: ";
		limparEntrada();
	}
	cout << "Digite o segundo número: ";
	while (!(cin >> b)) {
		cout << "Entrada inválida. Digite um número: ";
		limparEntrada();
	}
	limparEntrada();
	cout << "Resultado: " << (a + b) << "\n";
}

void opcaoInverterString() {
	cout << "Digite uma linha de texto: ";
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	cout << "Invertido: " << s << "\n";
}

void opcaoMostrarDataHora() {
	time_t agora = time(nullptr);
	char buf[64];
	tm localt;
#ifdef _WIN32
	localtime_s(&localt, &agora);
#else
	localtime_r(&agora, &localt);
#endif
	strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", &localt);
	cout << "Data/Hora local: " << buf << "\n";
}

int main() {
	while (true) {
		int opc = lerOpcao();
		if (opc == 0) {
			cout << "Saindo...\n";
			break;
		}
		switch (opc) {
			case 1:
				opcaoSomar();
				pausa();
				break;
			case 2:
				opcaoInverterString();
				pausa();
				break;
			case 3:
				opcaoMostrarDataHora();
				pausa();
				break;
			default:
				cout << "Opção inválida. Tente novamente.\n";
				pausa();
				break;
		}
	}
	return 0;
}
