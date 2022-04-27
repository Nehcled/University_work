import './App.css';
import React from 'react';
import { Routes, Route } from "react-router-dom";
import Home from './view/Home';
import StudentCourseTable from './compoents/StudentCourseTable';
import Profile from './view/Profile';
import NavBar from './compoents/NavBar'

function App() {
  return (
    <div className="App">
      <NavBar />
      <div className='app-body'>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/courseTable" element={<StudentCourseTable />} />
          <Route path="/profile" element={<Profile />} />
        </Routes>
      </div>
    </div>
  );

}

export default App;
