import java.awt.event.*;
import java.awt.*;

class GrLibrary extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e){};
    public void windowClosing(WindowEvent e){
        dispose();
        System.exit(0);
    };
    public void windowClosed(WindowEvent e){};
    public void windowIconified(WindowEvent e){};
    public void windowDeiconified(WindowEvent e){};
    public void windowActivated(WindowEvent e){};
    public void windowDeactivated(WindowEvent e){};
    public void paint(Graphics g){
        Dimension rc=getSize();
        int RH=rc.width;
        int RW=rc.height;
        g.setColor(Color.white);
    }
    public GrLibrary(){
        super("Графічні примітиви. Малюємо!");
        addWindowListener(this);
        setSize(640,480);
        show();
    }
    public static void main(String[] args) {
        new GrLibrary();
    }
}
