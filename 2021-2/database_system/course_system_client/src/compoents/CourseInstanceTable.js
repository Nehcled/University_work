import React from 'react';
import { Stack, Button, Form, FormControl } from 'react-bootstrap'
import Course from './Course';

class CourseInstanceTable extends React.Component {
    componentDidMount() {
        this.loadCourseData()
    }

    async loadCourseData() {
        const requestOptions = {
            method: 'GET',
            headers: { 'Content-Type': 'application/json' },
        }
        try {
            const response = await fetch('/api/instanceCourse', requestOptions);
            const json = await response.json();
            this.setState({ courseData: json.courseData });
        } catch (e) {
            console.error(`error:${e.message}`);
        }
    }

    render() {
        const courseData = this.state.courseData || [];
        const courseList = courseData.map((course, i) => (
            <Course key={i} course={course} />
        ))
        return (
            <div className='course-table'>
                <h1>課程清單</h1>
                <div className='course-list'>
                    <Stack gap={courseData.length}>
                        {courseList}
                    </Stack>
                </div>
                <Form horizontal='true' onSubmit={(e) => this.handleSubmit(e)}>
                    <h1>加選課程</h1>
                    <div className='line-form'>
                        <FormControl className='form-control' type='text' placeholder='課程編號' onBlur={(e) => this.handleChange(e)} />
                        <Button className='button' variant='primary' type='submit'>加選</Button>
                    </div>
                </Form>
            </div>
        )
    }

}

export default CourseInstanceTable;