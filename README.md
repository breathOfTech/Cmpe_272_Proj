![logo](https://user-images.githubusercontent.com/10326883/36414375-e9339856-15d6-11e8-9bbd-035581f8416e.jpg)
<h1>Title: StayConnected</h1>

<h3>Team Members</h3>

- Faisal Rahman <br/>
- Pratik Baniya <br/>
- Vera Wang <br/>
- Tejal Laxmidas Padharia <br/>           

<h3>Introduction</h3>
<p>
<strong>Scope:</strong> <br/>
Our design may be a Distributed Active Climate Control System for large data centers. The server racks are laid out in grids with cooling units and lighting units (for maintenance and operation). <br/>

<strong>Our system would utilize distributed low cost IoT sensors to perform these tasks including: </strong> <br/>
- Ambient Temperature Monitoring <br/>
- HVAC Control (Small servo used to showcase fan operation) <br/>
- Motion Sensing <br/>
- Lighting Control <br/><br/>
<strong>Features: </strong><br/>
- Raspberry Pi Computing Module (Parent Node/Stand alone) <br/>
- WiFi MicroController (Optional for increased complexity) (Child Node/Stand alone IFFT Device) <br/>
- Redundancy and node failover i.e. all nodes communicate at all times <br/>
- Constrain Resolver to distribute communication load among nodes to balance traffic <br/>
</p>

<h3>Architecture Diagram</h3>

![architecture diagram](https://user-images.githubusercontent.com/10326883/36414464-346e6648-15d7-11e8-855d-7d48fbc70ca2.jpg)

<h3>Technology Used</h3>
<strong>Temperature Sensor:</strong><br/>

- Temperature Sensor Package <br/>

<strong>Proximity Sensors: </strong><br/>

- Proximity IR Motion Sensor <br/>
- Microwave Radar Motion Sensor <br/>

<strong>Distributed Computing Unit:</strong><br/>

- Raspberry Pi

<strong>MicroController Unit:</strong><br/>

- Arduino Uno MicroController <br/>
- Particle Photon <br/>
- SparkFun ESP8266 <br/>

<strong>Smart Bulb:</strong><br/>

- TP Link Smart Bulb - Node.js library https://github.com/konsumer/tplink-lightbulb <br/>

<strong>Servo: </strong><br/>

- 3 V DC Motor<br/>
<br/>
<strong>Communication:</strong><br/>
<strong>Wireless:</strong><br/>

- WiFi (Over TCP/IP) <br/>
- Bluetooth Low Energy (Over Bluetooth LE broadcast) <br/>

<strong>Wired:</strong><br/>

- I2C (Serial Communication connected to GPIO pins) <br/>
- SPI <br/>
- Ethernet (Raspberry Pi Only)<br/>
<br/>
<strong>Software System Overview:</strong><br/>
<strong>Cloud Platform - IBM Bluemix </strong><br/>
<strong>Languages: </strong><br/>

- Arduino ~ C++ (Simplified) <br/>
- JavaScript (Node.js) <br/>
<br/>
<strong>FrameWork - MERN Stack </strong> <br/>

- MongoDB - No SQL DB <br/>
- ExpressJS - Server Framework Running on NodeJS <br/>
- ReactJS - Web Application Framework from Facebook <br/>
- NodeJS - Runtime environment built on google chrome v8 engine <br/>
<br/>
<strong>IoT Framework (Ready Made): </strong><br/>

- Node Red <br/>

<h3>Future Enchancements</h3>

<h3>URL</h3>

<h3>Environment Set Up Requirement</h3>

<h3>Project Setup Procedue</h3>

