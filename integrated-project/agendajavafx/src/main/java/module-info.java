module br.ufes.inf.nemo.agendajavafx {
    requires javafx.controls;
    requires javafx.fxml;
	requires org.apache.httpcomponents.httpclient;
	requires org.apache.httpcomponents.httpcore;
	requires com.google.gson;
	requires javafx.base;
	requires javafx.graphics;

    opens br.ufes.inf.nemo.agendajavafx to javafx.fxml;
    exports br.ufes.inf.nemo.agendajavafx;
}
