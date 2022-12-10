using System.Collections;

using System.Collections.Generic;

using UnityEngine;

using System.IO.Ports;

using System.Threading;

using System;



public class SerialScript : MonoBehaviour

{

    SerialPort sp = new SerialPort();

    void Start()

    {

        sp.PortName = "COM6";     // 포트번호

        sp.BaudRate = 115200;      // BaudRate

        sp.DataBits = 8;

        sp.Parity = Parity.None;

        sp.StopBits = StopBits.One;



        sp.Open();

    }



    // Update is called once per frame

    void Update()

    {

        switch (Input.inputString)

        {

            case "W":

            case "w":

                Debug.Log("press w");

                sp.WriteLine("w");

                break;



            case "A":

            case "a":

                Debug.Log("press a");

                sp.WriteLine("a");

                break;



            case "S":

            case "s":

                Debug.Log("press s");

                sp.WriteLine("s");

                break;



            case "D":

            case "d":

                Debug.Log("press d");

                sp.WriteLine("d");

                break;

        }

    }



    private void OnApplicationQuit()

    {

        sp.Close();

    }

}