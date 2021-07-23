module br.ufes.inf.nemo {
    requires javafx.controls;
    requires javafx.fxml;

    opens br.ufes.inf.nemo to javafx.fxml;
    exports br.ufes.inf.nemo;
}
