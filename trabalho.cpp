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
	cout << "1) Adivinha o número\n";
	cout << "2) Inverter uma palavra\n";
	cout << "3) Inverter Minusculas por Maiusculas\n";
	cout << "0) Sair\n";
	cout << "Escolha uma opção: ";
	if (!(cin >> opc)) {
		limparEntrada();
		return -1;
	}
	limparEntrada();
	return opc;
}

void opcao_adv_numero() {
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

void opcao_trocar_minuscolas_por_maiuscolas() {
	cout << "Digite uma linha de texto: ";
	string s;
	getline(cin, s);
	for (char& c : s) {
		if (islower(c)) {
			c = toupper(c);
		} else if (toupper(c)) {
			c = islower(c);
		}
	}
	cout << "Resultado: " << s << "\n";
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
				opcao_adv_numero();
				pausa();
				break;
			case 2:
				opcaoInverterString();
				pausa();
				break;
			case 3:
				opcao_trocar_minuscolas_por_maiuscolas();
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
