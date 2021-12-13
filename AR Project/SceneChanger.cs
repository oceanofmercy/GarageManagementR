using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneChanger : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void EndGame()
    {
        Application.Quit();
    }
    public void LoadMenu()
    {
        SceneManager.LoadScene("Menu");
    }
    public void LoadCarMenu()
    {
        SceneManager.LoadScene("CarMenu");
    }
    public void LoadRetro()
    {
        SceneManager.LoadScene("RetroCar");
    }
    public void LoadTocus()
    {
        SceneManager.LoadScene("TocusCar");
    }
    public void LoadLambo()
    {
        SceneManager.LoadScene("LamboCar");
    }
    public void LoadRaceCar()
    {
        SceneManager.LoadScene("RaceCar");
    }
}
