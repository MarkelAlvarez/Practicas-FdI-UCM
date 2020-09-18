package simulator.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.RenderingHints;
import java.io.File;
import java.io.IOException;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.JComponent;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Junction;
import simulator.model.Road;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;
import simulator.model.Vehicle;

public class MapByRoadComponent extends JComponent implements TrafficSimObserver {

	private int x1;
	private int x2;
	private int y;
	private int i;
	private int xCoche;

	private RoadMap _map;
	private Image _car;
	private Image _clima;
	private Image _cont;
	
	private static final int _JRADIUS = 10;
	private static final Color _BG_COLOR = Color.WHITE;
	private static final Color _JUNCTION_COLOR = Color.BLUE;
	private static final Color _JUNCTION_LABEL_COLOR = new Color(200, 100, 0);
	private static final Color _GREEN_LIGHT_COLOR = Color.GREEN;
	private static final Color _RED_LIGHT_COLOR = Color.RED;
		
	public MapByRoadComponent(Controller ctrl) {
		
		initGUI();
		setPreferredSize(new Dimension(300, 200));
		ctrl.addObserver(this);	
	}

	private void initGUI() {
		
		_car = loadImage("car.png");
	}

	public void paintComponent(Graphics graphics) {
		
		super.paintComponent(graphics);
		
		Graphics2D g = (Graphics2D) graphics;
		g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);

		// clear with a background color
		g.setColor(_BG_COLOR);
		g.clearRect(0, 0, getWidth(), getHeight());

		if (_map == null || _map.getJunctions().size() == 0/*TODO: cambiar esto*/)
		{
			g.setColor(Color.red);
			g.drawString("No map by road yet!", getWidth() / 2 - 50, getHeight() / 2);
		}
		else
		{
			//updatePrefferedSize();
			drawMap(g);
		}
	}

	private void drawMap(Graphics g) {
		
		i = 0;
		x1 = 50;
		x2 = getWidth() - 100;
		
		for (Road r : _map.getRoads())
		{	
			y = (i+1)*50;
			//Dibuja id carretera, la linea  
			g.setColor(Color.BLACK);
			g.drawString(r.getId(), x1 - 30, y + _JRADIUS/2);
			g.drawLine(x1, y, x2, y);
						
			//Dibuja los circulos del principio
			g.setColor(_JUNCTION_COLOR);
			g.fillOval(x1 - _JRADIUS/2, y - _JRADIUS/2, _JRADIUS, _JRADIUS);
			
			//TODO: comprobar que esta bien
			//Dibuja los circulos del final de un color u otro
			int idx = r.getCruceDestino().getIndiceVerde();
			if (idx != -1 && r.equals(r.getCruceDestino().getListaEntrantes().get(idx)))
			{
				g.setColor(_GREEN_LIGHT_COLOR);
			}
			else
			{
				g.setColor(_RED_LIGHT_COLOR);
			}
			g.fillOval(x2 - _JRADIUS/2, y - _JRADIUS/2, _JRADIUS, _JRADIUS);
			
			//Dibuja los nombres de los junction
			g.setColor(_JUNCTION_LABEL_COLOR);
			g.drawString(r.getCruceOrigen().toString(), x1, y - _JRADIUS);
			g.drawString(r.getCruceDestino().toString(), x2, y - _JRADIUS);
			
			//Dibuja la imagen del clima
			switch(r.getCondMet())
			{
				case SUNNY:
					_clima = loadImage("sun.png");
					break;
				case CLOUDY:
					_clima = loadImage("cloud.png");
					break;
				case RAINY:
					_clima = loadImage("rain.png");
					break;
				case WINDY:
					_clima = loadImage("wind.png");
					break;
				case STORM:
					_clima = loadImage("storm.png");
					break;
			}
			g.drawImage(_clima, x2 + 15, y - _JRADIUS*2, 32, 32, this);
			
			//Dibuja la imagen de la contaminación
			int c = (int) Math.floor(Math.min((double)r.getContTotal()/(1.0 + (double)r.getLimiteCont()),1.0) / 0.19);
			switch(c)
			{
				case 0:
					_cont = loadImage("cont_0.png");
					break;
				case 1:
					_cont = loadImage("cont_1.png");
					break;
				case 2:
					_cont = loadImage("cont_2.png");
					break;
				case 3:
					_cont = loadImage("cont_3.png");
					break;
				case 4:
					_cont = loadImage("cont_4.png");
					break;
				case 5:
					_cont = loadImage("cont_5.png");
					break;
				case 6:
					_cont = loadImage("cont_6.png");
					break;
			}
			g.drawImage(_cont, x2 + 55, y - _JRADIUS*2, 32, 32, this);
			
			//Dibuja el coche y calcula el movimiento
			if (!r.getVehiculos().isEmpty())
			{
				for (Vehicle v : r.getVehiculos())
				{
					xCoche = x1+(int)((x2-x1)*((double)v.getLocalizacion()/(double)r.getLongitud()));
					g.setColor(_GREEN_LIGHT_COLOR);
					g.drawString(v.getId(), xCoche, y - _JRADIUS-5);
					g.drawImage(_car, xCoche, y - _JRADIUS-3, 16, 16, this);
				}
			}			
			
			i++;
		}
	}
	
	// this method is used to update the preffered and actual size of the component,
	// so when we draw outside the visible area the scrollbars show up
	private void updatePrefferedSize() {
		
		int maxW = 200;
		int maxH = 200;
		
		for (Junction j: _map.getJunctions())
		{
			maxW = Math.max(maxW, j.getX());
			maxH = Math.max(maxH, j.getY());
		}
		
		maxW += 20;
		maxH += 20;
		
		if ((maxW > getWidth()) || (maxH > getHeight()))
		{
			setPreferredSize(new Dimension(maxW, maxH));
			setSize(new Dimension(maxW, maxH));
		}
	}

	// loads an image from a file
	private Image loadImage(String img) {
		
		Image i = null;
		
		try {
			return ImageIO.read(new File("resources/icons/" + img));
		} catch (IOException e) {
		}
		
		return i;
	}

	public void update(RoadMap map) {
		
		_map = map;
		repaint();
	}

	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		
		update(map);
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		
		update(map);
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		
		update(map);
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		
		update(map);
	}

	@Override
	public void onError(String err) {
		
	}
}