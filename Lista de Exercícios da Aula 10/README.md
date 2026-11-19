Questão 3 — Visibilidade na herança

Na herança pública, o nível de acesso define quem pode enxergar cada membro da classe base. O atributo public (nome) fica totalmente aberto, podendo ser acessado tanto dentro da classe derivada quanto fora dela, como no main(). Já o protected (salario) fica escondido de código externo, mas continua acessível dentro da classe filha (Gerente). Por fim, o private (documento) é exclusivo da própria classe Funcionario — nem mesmo o Gerente consegue acessá-lo diretamente, precisando de métodos públicos ou protegidos para manipular esse dado. 

Questão 4 — Polimorfismo dinâmico

Com a palavra-chave virtual na classe base, o programa utiliza vinculação dinâmica (late binding): em tempo de execução, ele verifica o tipo real de cada objeto apontado na coleção e executa o método específico de Carro ou Motocicleta. Quando removemos o virtual, passa a valer a vinculação estática (early binding), onde o compilador olha apenas para o tipo do ponteiro (Veiculo*) durante a compilação e acaba chamando sempre a implementação genérica da classe base para todos os itens.   

Questão 5 — Classe abstrata e funções virtuais puras

Não é possível instanciar diretamente a classe FormaGeometrica porque ela possui funções virtuais puras (= 0), o que a torna uma classe abstrata. Na prática, ela funciona apenas como um molde ou contrato que obriga as classes derivadas (Retangulo e Circulo) a implementarem seus próprios cálculos de área e perímetro. Como esses métodos não têm implementação na classe base, criar um objeto FormaGeometrica deixaria comportamentos incompletos, por isso o próprio compilador bloqueia a instanciação.  

Questão 6 — Destrutor virtual e gerenciamento de memória

Se o destrutor da classe Recurso não fosse virtual, ao executar delete em um ponteiro do tipo base apontando para um objeto RecursoArquivo, o C++ chamaria apenas o destrutor de Recurso e ignoraria o da classe derivada. Como consequência, o código responsável por liberar a memória ou o recurso alocado especificamente em RecursoArquivo nunca seria executado, provocando vazamento de memória e de recursos (memory/resource leak).   

Questão 7 — Herança múltipla e problema do diamante

O problema do diamante surge quando uma classe (Multifuncional) herda de duas classes (Impressora e Scanner) que descendem da mesma classe base (Dispositivo). Sem a herança virtual, Multifuncional acaba recebendo duas cópias independentes de Dispositivo, gerando um erro de ambiguidade na compilação ao tentar acessar identificador ou exibirIdentificador(). Ao usar virtual public Dispositivo nas classes intermediárias, garantimos que ambas compartilhem uma única instância da classe base, eliminando a duplicação.   

Questão 8 — Projeto integrador: sistema de notificações

A estrutura aplica herança ao fazer Email, SMS e NotificacaoPush estenderem Notificacao, e abstração ao definir o contrato enviar() = 0 na classe base sem expor os detalhes de cada envio. O polimorfismo dinâmico aparece ao percorrer o vetor de ponteiros Notificacao* e chamar enviar(), deixando que cada objeto execute sua própria versão com override sem precisar de if ou switch para checar o tipo. Isso atende diretamente ao princípio Aberto/Fechado (OCP), pois permite adicionar novos canais de notificação no futuro sem precisar alterar o código que já gerencia os envios.
