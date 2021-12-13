using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Car : MonoBehaviour
{
    public string carName;
    public string colour;
    public int cost;
    public string modelNo;

    public string checkCarName()
    {
        return carName;
    }

    public string checkColour()
    {
        return colour;
    }

    public int Checkcost()
    {
        return cost;
    }

    public string checkModelNo()
    {
        return modelNo;
    }
}
