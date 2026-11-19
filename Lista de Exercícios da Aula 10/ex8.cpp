#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Notificacao {
protected:
    string mensagem;

public:
    Notificacao(string msg) {
        mensagem = msg;
    }

    virtual void enviar() = 0;

    virtual ~Notificacao() {
        cout << "[Notificacao] Base destruida." << endl;
    }
};

class Email : public Notificacao {
private:
    string destino;

public:
    Email(string dest, string msg) : Notificacao(msg) {
        destino = dest;
    }

    void enviar() override {
        cout << "[Email para " << destino << "]: " << mensagem << endl;
    }

    ~Email() {
        cout << "[Email] Finalizou envio para " << destino << "." << endl;
    }
};

class SMS : public Notificacao {
private:
    string telefone;

public:
    SMS(string tel, string msg) : Notificacao(msg) {
        telefone = tel;
    }

    void enviar() override {
        cout << "[SMS para " << telefone << "]: " << mensagem << endl;
    }

    ~SMS() {
        cout << "[SMS] Finalizou envio para " << telefone << "." << endl;
    }
};

class NotificacaoPush : public Notificacao {
private:
    string app;

public:
    NotificacaoPush(string nomeApp, string msg) : Notificacao(msg) {
        app = nomeApp;
    }

    void enviar() override {
        cout << "[Push no app " << app << "]: " << mensagem << endl;
    }

    ~NotificacaoPush() {
        cout << "[Push] Finalizou envio no app " << app << "." << endl;
    }
};

int main() {
    vector<Notificacao*> fila;

    fila.push_back(new Email("cliente@email.com", "Seu pedido foi aprovado."));
    fila.push_back(new SMS("+55 66 99999-0000", "Codigo de verificacao: 4821"));
    fila.push_back(new NotificacaoPush("BancoApp", "Compra de R$ 120,00 realizada."));

    cout << "--- Enviando notificacoes ---" << endl;
    for (int i = 0; i < fila.size(); i++) {
        fila[i]->enviar(); // sem if/switch checando o tipo
    }

    cout << "\n--- Limpando memoria ---" << endl;
    for (int i = 0; i < fila.size(); i++) {
        delete fila[i]; // chama destrutor da derivada e depois o da base
    }
    fila.clear();

    return 0;
}