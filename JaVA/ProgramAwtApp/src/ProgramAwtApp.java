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
        Insets in=getInsets();

        int RH=rc.width;
        int RW=rc.height;

        int minX=in.left; int maxX=RH-in.right;
        int minY=in.top;  int maxY=RW-in.bottom;

        int cx,cy,dx,dy;

        cx=Math.abs(maxX-minX)/2;
        cy=Math.abs(maxY-minY)/2;
        dx=maxX/10;
        dy=maxY/10;

        g.setColor(new Color(0x00D30094));
        String txt="Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms",Font.PLAIN,24));
        int nf=g.getFontMetrics().stringWidth(txt);
        g.drawString(txt,nf/2-220,nf/2-180);

        g.setColor(new Color(0xFA5099EE));
        g.setFont(new Font("Times New Roman",Font.BOLD|Font.PLAIN,28));
        FontMetrics fm; fm=getFontMetrics(g.getFont());
        g.drawString("Перші кроки: ",20,90);

        Graphics2D g2=(Graphics2D) g;
        g2.setStroke(new BasicStroke(3.0f));

        g.setColor(new Color(0x0032CD32));
        int x1,y1,x2,y2,k,i;
        int d=140; y1 = 110; y2=d;
        for (k = 0; k < 3; k++)
        {
            x1 =90; x2=d;
            for (i = 0; i <4; i++)
            {
                g.drawRect(x1, y1 , x2,y2);
                x1+=d+20;
            }
            y1 += d+20;
        }



    }
    public GrLibrary(){
        super("Графічні примітиви. Малюємо!");
        addWindowListener(this);
        setLayout(null);
        setLocation(240,200);
        setSize(800,600);
        show();
    }
    public static void main(String[] args) {
        new GrLibrary();
    }
}